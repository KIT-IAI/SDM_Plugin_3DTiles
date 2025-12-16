#include "threeDTilesAction.hpp"
#include "threeDTilesDialogImpl.h"

#include <ifcdb/IFCDBInterfaceVersion.hpp>
#include "PluginInterfaceVersion.hpp"

#include <ComponentRegistry.hpp>
#include <ifcdb/GeomLibStructs.h>
#include <stdutils/utf8.hpp>
#include <stdutils/process.hpp>
#include <filesystem>


IMPLEMENT_PLUGIN(threeDTilesPlugin)

void threeDTilesAction::execute() const
{
    const auto dlg = new threeDTilesDialogImpl(nullptr, wxID_ANY, wxT("3DTiles-Downloader"), wxDefaultPosition, wxSize(400, 400), wxDEFAULT_FRAME_STYLE | wxSTAY_ON_TOP);

    double lon = m_db->getGeoReference().m_LatLonBoundigBox.getCenter().x;
    double lat = m_db->getGeoReference().m_LatLonBoundigBox.getCenter().y;

    IfcDB::Point min = m_db->getGeoReference().m_ModelBoundingBox.getMin();
    IfcDB::Point max = m_db->getGeoReference().m_ModelBoundingBox.getMax();
    double distance = min.dist(max);
    double radius = distance / 2.0f;

    //minimal radius
    if (radius < 35.0) radius = 35.0;

    if (m_3DTilesAPIKey.empty())
    {
        MessageBox(0, L"no 3dTiles api Key found in Settings", L"Error", 0);
        return;
    }

    dlg->setApiKey(m_3DTilesAPIKey);
    dlg->setGeoInfos(lat, lon, radius);
    dlg->ShowModal();

    if (dlg->m_openFile)
    {
        //openFile
        m_app->loadDocument(stdutils::fromUtf8(dlg->getFilePath() + "tileset.json"), true);
    }
}

sdm::plugin::ComponentInfo threeDTilesPlugin::getComponentInfo(const sdm::plugin::RequiredComponent& requiredComponent) const
{
    sdm::plugin::ComponentRegistry availableComponents;
    availableComponents.addAvailable(IFCDB_INTERFACE_COMPONENT_NAME, IFCDB_INTERFACE_COMPONENT_VERSION, IFCDB_INTERFACE_COMPONENT_HINT, std::atoi(IFCDB_INTERFACE_COMPONENT_DATE.data()));
    availableComponents.addAvailable(PLUGIN_INTERFACE_COMPONENT_NAME, PLUGIN_INTERFACE_COMPONENT_VERSION, PLUGIN_INTERFACE_COMPONENT_HINT, std::atoi(PLUGIN_INTERFACE_COMPONENT_DATE.data()));

    return availableComponents.getInfo(requiredComponent);
}

const sdm::plugin::InitializationState& threeDTilesPlugin::getInitializationState() const
{
    return m_initState;
}
