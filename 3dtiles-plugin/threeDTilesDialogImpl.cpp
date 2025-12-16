#include "threeDTilesDialogImpl.h"

#include <stdio.h>
#include <tchar.h>
#include <stdutils/executable.hpp>
#include <stdutils/utf8.hpp>

IMPLEMENT_APP_NO_MAIN(MyApp)

bool MyApp::OnInit()
{
    return true;
}

int MyApp::OnExit()
{
    return 0;
}


threeDTilesDialogImpl::threeDTilesDialogImpl(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : threeDTilesDialog(parent, id, title, pos, size, style)
{
    Centre();

    SetDoubleBuffered(true);


    wxSize minSize = this->GetBestSize();
    this->SetSize(minSize);
}

threeDTilesDialogImpl::~threeDTilesDialogImpl()
{
}

void threeDTilesDialogImpl::setApiKey(std::wstring key)
{
    m_apiKey = key;
}


void threeDTilesDialogImpl::writeClipValueInJson() {

    bool clipValue = m_checkBox1->GetValue();



}

void threeDTilesDialogImpl::m_buttonDownloadOnButtonClick(wxCommandEvent& event)
{
    wxBeginBusyCursor();

    const auto lat = m_textLat->GetValue();
    const auto lon = m_textLon->GetValue();
    const auto rad = m_textRad->GetValue();
    m_filePath = m_dirPicker1->GetDirName().GetAbsolutePath();

    
   
    wxString argString = "0 " + lat + " " + lon + " " + rad + " " + m_apiKey + " " + m_filePath + " " + std::to_string(m_checkBox1->GetValue());

    //download files via exe

    STARTUPINFO si{};
    PROCESS_INFORMATION pi{};
  
    si.cb = sizeof(STARTUPINFO);
  
    auto executableDir = stdutils::findExecutableFileName().parent_path()/"plugins"/"3dtilesplugin"/"main.exe";
    
    // Start the child process. 
    if (!CreateProcess(std::wstring(executableDir).c_str(),   //module name 
        stdutils::fromUtf8(argString).data(),        // Command line
        NULL,           // Process handle not inheritable
        NULL,           // Thread handle not inheritable
        FALSE,          // Set handle inheritance to FALSE
        CREATE_NEW_CONSOLE,              // No creation flags
        NULL,           // Use parent's environment block
        NULL,           // Use parent's starting directory 
        &si,            // Pointer to STARTUPINFO structure
        &pi)           // Pointer to PROCESS_INFORMATION structure
        )
    {
        printf("CreateProcess failed (%d).\n", GetLastError());
        return;
    }
    
    // Wait until child process exits.
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Close process and thread handles. 
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    wxEndBusyCursor();
    Close();

    m_openFile = true;
}
