#ifndef ACCEUILFRAME_H_INCLUDED
#define ACCEUILFRAME_H_INCLUDED

//include classique
#include "wx/wx.h"
#include "Customer.hpp"
#include <vector>
//Definition de notre classe mainFrame
class AcceuilFrame : public wxFrame
{
public:
	//constructeur
	AcceuilFrame();
	//destructeur
	~AcceuilFrame();

	wxFrame* m_frame;
private:
	vector< client > clientsTblG1; //stock la totalité des profil Générale rc banque
	vector< client > clientsTblG2; //stock la totalité des profil idem lille
	vector< client > clientsTblG3; //stock la totalité des profil idem paris

	wxRadioBox* m_radioBox1; //pointeur sur la radio box rc
	wxRadioBox* m_radioBox2; //pointeur sur la radio box lille
	wxRadioBox* m_radioBox3; //pointeur sur la radio box paris

	//id profil btn
	static const int ID_BTN_PROFIL, ID_BTN_CONNEXION_1, ID_BTN_CONNEXION_2, ID_BTN_CONNEXION_3;

	//event
	void OnButtonProfilClicked(wxCommandEvent& event);
	void OnButtonConnexion1Clicked(wxCommandEvent& event);
	void OnButtonConnexion2Clicked(wxCommandEvent& event);
	void OnButtonConnexion3Clicked(wxCommandEvent& event);

	//tabble des evenements
	DECLARE_EVENT_TABLE();
};

#endif