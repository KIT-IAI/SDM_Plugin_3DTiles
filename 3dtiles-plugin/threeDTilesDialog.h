///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/filepicker.h>
#include <wx/checkbox.h>
#include <wx/collpane.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class threeDTilesDialog
///////////////////////////////////////////////////////////////////////////////
class threeDTilesDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* latText;
		wxTextCtrl* m_textLat;
		wxStaticText* lonText;
		wxTextCtrl* m_textLon;
		wxStaticLine* m_staticline1;
		wxCollapsiblePane* m_collapsiblePane1;
		wxStaticText* m_staticText3;
		wxTextCtrl* m_textRad;
		wxStaticText* m_staticText41;
		wxDirPickerCtrl* m_dirPicker1;
		wxStaticText* clipText;
		wxCheckBox* m_checkBox1;
		wxStaticLine* m_staticline2;
		wxStdDialogButtonSizer* m_sdbSizer1;
		wxButton* m_sdbSizer1OK;
		wxButton* m_sdbSizer1Cancel;

		// Virtual event handlers, override them in your derived class
		virtual void m_buttonDownloadOnButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		threeDTilesDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 400,289 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxSTAY_ON_TOP );

		~threeDTilesDialog();

};

