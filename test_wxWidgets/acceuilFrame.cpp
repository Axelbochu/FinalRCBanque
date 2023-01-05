#include "acceuilFrame.hpp"
#include "mainframe.h"
#include "Customer.hpp"
#include "Customer_for_JSON.hpp"
#include <string>
#include "inscriptionFrame.h"

const int AcceuilFrame::ID_BTN_PROFIL = wxNewId();
const int AcceuilFrame::ID_BTN_CONNEXION_1 = wxNewId();
const int AcceuilFrame::ID_BTN_CONNEXION_2 = wxNewId();
const int AcceuilFrame::ID_BTN_CONNEXION_3 = wxNewId();

BEGIN_EVENT_TABLE(AcceuilFrame, wxFrame)
	EVT_BUTTON(ID_BTN_PROFIL, AcceuilFrame::OnButtonProfilClicked)
	EVT_BUTTON(ID_BTN_CONNEXION_1, AcceuilFrame::OnButtonConnexion1Clicked)
	EVT_BUTTON(ID_BTN_CONNEXION_2, AcceuilFrame::OnButtonConnexion2Clicked)
	EVT_BUTTON(ID_BTN_CONNEXION_3, AcceuilFrame::OnButtonConnexion3Clicked)
END_EVENT_TABLE()


//constructeur
AcceuilFrame::AcceuilFrame() : wxFrame(NULL, wxID_ANY, _T("Connexion RCBanque"))
{
	wxPanel* panel = new wxPanel(this, -1);

	//on créer le boxsizer principal
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

		wxStaticBoxSizer* profilBox = new wxStaticBoxSizer(wxVERTICAL, panel, _T("Gestion de profils :"));
		//création du boutons add profil
		wxButton* newProfil = new wxButton(panel, ID_BTN_PROFIL, _T("Ajouter un Profil"));
		profilBox->Add(newProfil, 0, wxALL, 10);

		//test manuel
		clientsTblG1 = json_to_vector1();
		clientsTblG2 = json_to_vector2();
		clientsTblG3 = json_to_vector3();

		//gestion profil
		//radio box pour banque
		//rcBanque
		wxArrayString choicesProfil1, choicesProfil2, choicesProfil3;
		for (int i = 0; i < clientsTblG1.size(); i++)
		{
			choicesProfil1.push_back(clientsTblG1[i].nomGet());
		}
		for (int i = 0; i < clientsTblG2.size(); i++)
		{
			choicesProfil2.push_back(clientsTblG2[i].nomGet());
		}
		for (int i = 0; i < clientsTblG3.size(); i++)
		{
			choicesProfil3.push_back(clientsTblG3[i].nomGet());
		}

		//rc banque
		m_radioBox1 = new wxRadioBox(panel, wxID_ANY, _T("RC Banque Profil :"), wxDefaultPosition, wxDefaultSize, choicesProfil1, 6, wxRA_HORIZONTAL);
		profilBox->Add(m_radioBox1, 0, wxEXPAND);
		wxButton* connexion1 = new wxButton(panel, ID_BTN_CONNEXION_1, _T("Connexion..."));
		profilBox->Add(connexion1, 0, wxALL, 5);

		//lilloisBanque
		m_radioBox2 = new wxRadioBox(panel, wxID_ANY, _T("Lillois Banque Profil :"), wxDefaultPosition, wxDefaultSize, choicesProfil2, 6, wxRA_HORIZONTAL);
		profilBox->Add(m_radioBox2, 0, wxEXPAND);
		wxButton* connexion2 = new wxButton(panel, ID_BTN_CONNEXION_2, _T("Connexion..."));
		profilBox->Add(connexion2, 0, wxALL, 5);

		//ParisBanque
		m_radioBox3 = new wxRadioBox(panel, wxID_ANY, _T("BanquePARIS Profil :"), wxDefaultPosition, wxDefaultSize, choicesProfil3, 6, wxRA_HORIZONTAL);
		profilBox->Add(m_radioBox3, 0, wxEXPAND);
		wxButton* connexion3 = new wxButton(panel, ID_BTN_CONNEXION_3, _T("Connexion..."));
		profilBox->Add(connexion3, 0, wxALL, 5);

	mainSizer->Add(profilBox, 0, wxALL | wxEXPAND, 10);


	panel->SetSizer(mainSizer);
	mainSizer->SetSizeHints(this);
}

//Destructeur
AcceuilFrame::~AcceuilFrame()
{
	//liberations de mémoire nécessaire

}

//evenement clicked
void AcceuilFrame::OnButtonProfilClicked(wxCommandEvent& event) {

	InscriptionFrame* inscriptionFrame = new InscriptionFrame();
	inscriptionFrame->setFramePtn(inscriptionFrame);
	inscriptionFrame->Show();
	inscriptionFrame->mainframe = m_frame;
}

void AcceuilFrame::OnButtonConnexion1Clicked(wxCommandEvent& event) {
	int indexClient = m_radioBox1->GetSelection();
	vector< client > clientsTbl1 = json_to_vector1();
	MainFrame* frame = new MainFrame(&clientsTbl1[indexClient]);
	frame->Show();
	frame->m_frame = frame;
}

void AcceuilFrame::OnButtonConnexion2Clicked(wxCommandEvent& event) {
	int indexClient = m_radioBox2->GetSelection();
	vector< client > clientsTbl2 = json_to_vector2();
	MainFrame* frame = new MainFrame(&clientsTbl2[indexClient]);
	frame->Show();
	frame->m_frame = frame;
}

void AcceuilFrame::OnButtonConnexion3Clicked(wxCommandEvent& event) {
	int indexClient = m_radioBox3->GetSelection();
	vector< client > clientsTbl3 = json_to_vector3();
	MainFrame* frame = new MainFrame(&clientsTbl3[indexClient]);
	frame->Show();
	frame->m_frame = frame;
}