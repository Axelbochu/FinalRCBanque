#include "mainFrame.h"
#include "inscriptionFrame.h"
#include "depotFrame.h"
#include "epargneFrame.h"
#include "Customer.hpp"
#include "Customer_for_JSON.hpp"
#include <string>
#include "virementFrame.hpp"

//on affecte les identifiants aux boutons
const int MainFrame::ID_BTN_DEPOT = wxNewId();
const int MainFrame::ID_BTN_EPARGNE = wxNewId();
const int MainFrame::ID_BTN_VIREMENT = wxNewId();

//Definition de la table des evenements
BEGIN_EVENT_TABLE(MainFrame,wxFrame)
	EVT_BUTTON(ID_BTN_DEPOT,MainFrame::OnButtonDepotClicked)
	EVT_BUTTON(ID_BTN_EPARGNE, MainFrame::OnButtonEpargneClicked)
	EVT_BUTTON(ID_BTN_VIREMENT, MainFrame::OnButtonVirementClicked)
END_EVENT_TABLE()


//constructeur
MainFrame::MainFrame(client* actualClientConstructeur) : wxFrame(NULL, wxID_ANY, _T("RCBanque"))
{	
	
	actualClient = new client(actualClientConstructeur->numeroClientGet(), actualClientConstructeur->nomGet(), actualClientConstructeur->prenomGet(), actualClientConstructeur->dateNaissanceGet(), actualClientConstructeur->telGet(), actualClientConstructeur->comptecourantGet(), actualClientConstructeur->compteepargneGet(), actualClientConstructeur->interetGet());

	//creation panel principal
	wxPanel* panel = new wxPanel(this, -1);


	//on créer le wxBoxSizer Principal
	wxBoxSizer* mainsizer = new wxBoxSizer(wxVERTICAL);
		//radio box pour banque
		wxArrayString choices;
		choices.Add("RCBanque");
		choices.Add("LilloisBanque");
		choices.Add("BanqueParis");
		wxRadioBox* m_radioBanque = new wxRadioBox(panel, wxID_ANY, _T("A quelle banque se connecter ?"), wxDefaultPosition, wxDefaultSize, choices, 3, wxRA_HORIZONTAL);
		mainsizer->Add(m_radioBanque, 0, wxEXPAND);

		wxStaticBoxSizer* centralBox = new wxStaticBoxSizer(wxVERTICAL, panel, _T("Mon compte :"));
		if (actualClient != NULL) {
			//création static text acceuil
			std::string acceuilTextContainer = "Bonjour ";
			acceuilTextContainer += actualClient->nomGet();
			acceuilTextContainer += " ";
			acceuilTextContainer += actualClient->prenomGet();
			acceuilTextContainer += " !";
			wxString wxAcceuilTextContainer(acceuilTextContainer);
			wxStaticText* introName = new wxStaticText(panel, wxID_ANY, wxAcceuilTextContainer);
			centralBox->Add(introName, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 10);

			//static text num client
			
			std::string numClientTextContainer = "Numéro Client :  ";
			numClientTextContainer += std::to_string(actualClient->numeroClientGet());
			numClientTextContainer += " .";
			wxString wxnumClientTextContainer(numClientTextContainer);
			wxStaticText* introNumClient = new wxStaticText(panel, wxID_ANY, wxnumClientTextContainer);
			centralBox->Add(introNumClient, 0, wxLEFT|wxRIGHT|wxBOTTOM | wxALIGN_CENTER_HORIZONTAL, 10);



			//on créer le box sizer contenant les autres
			wxBoxSizer* accountContainer = new wxBoxSizer(wxHORIZONTAL);
			//on ajoute les comptes
			//compte dépot
			wxString depotAmount;
			depotAmount << actualClient->comptecourantGet();
			wxStaticBoxSizer* depotSizer = new wxStaticBoxSizer(wxVERTICAL, panel, _T("Compte de dépot :"));
			soldeDepot = new wxStaticText(panel, wxID_ANY, depotAmount);
			depotSizer->Add(soldeDepot, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 10);

			wxButton* plusDepot = new wxButton(panel, ID_BTN_DEPOT, _T("voir plus"));
			depotSizer->Add(plusDepot, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 0);
			accountContainer->Add(depotSizer, 1, wxALL | wxEXPAND, 10);

			//compte épargne
			wxString epargneAmount;
			epargneAmount << actualClient->compteepargneGet();
			wxStaticBoxSizer* epargneSizer = new wxStaticBoxSizer(wxVERTICAL, panel, _T("Compte Epargne :"));
			wxStaticText* soldeEpargne = new wxStaticText(panel, wxID_ANY,epargneAmount);
			epargneSizer->Add(soldeEpargne, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 10);

			wxButton* plusEpargne = new wxButton(panel, ID_BTN_EPARGNE, _T("voir plus"));
			epargneSizer->Add(plusEpargne, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 0);
			accountContainer->Add(epargneSizer, 1, wxALL | wxEXPAND, 10);
			centralBox->Add(accountContainer, 0, wxLEFT | wxRIGHT | wxBOTTOM | wxEXPAND, 5);

			wxButton* virementBtn = new wxButton(panel, ID_BTN_VIREMENT, _T("Virements"));
			centralBox->Add(virementBtn, 0, wxALL | wxALIGN_RIGHT, 10);
		}
		mainsizer->Add(centralBox, 0, wxALL | wxEXPAND, 10);

	//affectation sizer principal fenetre
	panel->SetSizer(mainsizer);
	//calcule taille minimal fenetre
	mainsizer->SetSizeHints(this);

	//On affiche dymaquiment les soldes
	//............
	// .............
	//fin
}

//Destructeur
MainFrame::~MainFrame()
{
	//liberations de mémoire nécessaire
	
}

//evenement clicked
void MainFrame::OnButtonDepotClicked(wxCommandEvent& event) {
	DepotFrame* depotFrame = new DepotFrame();
	depotFrame->setSolde(actualClient);
	depotFrame->Show();
}

void MainFrame::OnButtonEpargneClicked(wxCommandEvent& event) {
	EpargneFrame* epargneFrame = new EpargneFrame();
	epargneFrame->setSolde(actualClient);
	epargneFrame->Show();
}


void MainFrame::OnButtonVirementClicked(wxCommandEvent& event) {
	VirementFrame* virementframe = new VirementFrame();
	virementframe->setActiveClient(actualClient);
	virementframe->Show();
	virementframe->centralFrame = virementframe;
	virementframe->pastFrame = m_frame;
}