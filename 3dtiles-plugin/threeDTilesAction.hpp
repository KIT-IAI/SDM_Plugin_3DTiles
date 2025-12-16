#pragma once
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <Plugin.hpp>
#include <ActionFeatureHelper.hpp>

#include <AppFeatureHelper.hpp>

#include <SettingsFeature.h>

#include <DocumentObserver.hpp>

#include <ifcdb/IfcDbInclude.h>
#include <ifcdb/utils/PopulationObserver.hpp>



//Menüeintrag
class threeDTilesAction : public sdm::plugin::ActionFeatureHelper
{
public:
    threeDTilesAction(sdm::plugin::AppFeatureHelper &app) : ActionFeatureHelper("Download 3D-Tiles") {
        m_app = &app;
        wxInitialize();
    }
    ~threeDTilesAction() {
        wxUninitialize();
    }

    void execute() const override;

    std::wstring m_3DTilesAPIKey;
    sdm::plugin::AppFeatureHelper* m_app;

    IfcDB::Populationi* m_db = nullptr;
};


class threeDTilesPlugin : public sdm::plugin::Plugin
{
public:
    threeDTilesPlugin() {
    m_features.emplace_back(&m_threeDTilesAction);
    m_features.emplace_back(&m_app);
    m_features.emplace_back(&m_settingsFeature);

    m_settingsFeature.attach([&](sdm::plugin::SettingsInterface* s) { 
        m_threeDTilesAction.m_3DTilesAPIKey = s->getSettings().m_Google3DTilesAPIKey;
        });

    m_features.emplace_back(&m_documentObserverImpl);

    m_documentObserverImpl.attach([&](IfcDB::Populationi* popi) {
        m_threeDTilesAction.m_db = popi;
        });

    }
    ~threeDTilesPlugin() override = default;

    sdm::plugin::Version getInterfaceVersion() const override { return sdm::plugin::Version(); }
    sdm::plugin::PluginInfo getInfo() const override {
        sdm::plugin::PluginInfo info;
        info.name = "3D Tiles Downloader";
        info.description = "";
        info.version = { 1, 0 };

        return info;
    }
    std::vector<sdm::plugin::Feature*> getFeatures() const override { 


        return m_features; 
    }

    sdm::plugin::ComponentInfo getComponentInfo(const sdm::plugin::RequiredComponent& requiredComponent) const override;
    const sdm::plugin::InitializationState& getInitializationState() const override;

private:
    sdm::plugin::AppFeatureHelper m_app;

    threeDTilesAction m_threeDTilesAction{ m_app };
    std::vector<sdm::plugin::Feature*> m_features;
    sdm::plugin::SettingsFeature m_settingsFeature;

    sdm::plugin::DocumentObserverImpl m_documentObserverImpl;
    sdm::plugin::InitializationState m_initState;
};

