#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <filesystem>


#include "threeDTilesDialog.h"

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
    virtual int OnExit();
};




class threeDTilesDialogImpl : public threeDTilesDialog
{
public:
    threeDTilesDialogImpl(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("3DTiles-Downloader"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(328, 343), long style = wxDEFAULT_DIALOG_STYLE);
    ~threeDTilesDialogImpl();

    void writeClipValueInJson();
    void setApiKey(std::wstring key);
    void setGeoInfos(double lat, double lon, double radius) {
        m_textLon->SetValue(std::to_string(lon));
        m_textLat->SetValue(std::to_string(lat));

        if (radius > 10000) {

            std::string info = "Model Bounding-Box Radius is " + std::to_string(radius) + " and is set to default value";
            std::wstring widestr = std::wstring(info.begin(), info.end());

            MessageBox(0, widestr.c_str(), L"Warning", 0);
            
            m_textRad->SetValue(std::to_string(100.0));
        }
        else
        {
            m_textRad->SetValue(std::to_string(radius));
        }
        

        m_dirPicker1->SetDirName(wxFileName((std::filesystem::temp_directory_path()/"3dtilesdownload/").string()));

    }
    void m_buttonDownloadOnButtonClick(wxCommandEvent& event);

    wxString getFilePath() { return m_filePath; }

    bool m_openFile = false;

private:
    std::wstring m_apiKey;
    wxString m_filePath;

};