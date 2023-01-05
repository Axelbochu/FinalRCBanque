#include "acceuilFrame.hpp"
#include "inscriptionFrame.h"
#include "depotFrame.h"
#include "epargneFrame.h"
#include "Customer.hpp"
#include <string>


//constructeur
AcceuilFrame::AcceuilFrame() : wxFrame(NULL, wxID_ANY, _T("RCBanque"), wxPoint(30,30),wxSize(800,600))
{
    //création du menu
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(NULL, "&Ajouter un client...\tCtrl-A",
        "Ajouter un client");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&Gestion profil");
    menuBar->Append(menuHelp, "&Aide");

    SetMenuBar(menuBar);
    //fin menu

    //page principale
    wxPanel* panel = new wxPanel(this, -1);
       
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

        wxBoxSizer* upSizer = new wxBoxSizer(wxHORIZONTAL);
            wxPanel* upPanel = new wxPanel();
            upPanel->SetBackgroundColour(wxColor(220, 90, 90));
                
            upSizer->Add(upPanel, 0, wxEXPAND, 0);
        mainSizer->Add(upSizer, 3, wxDOWN, 10);

    wxBoxSizer* downSizer = new wxBoxSizer(wxHORIZONTAL);

    mainSizer->Add(downSizer, 7, wxALL, 0);
    //affectation sizer principal fenetre
    panel->SetSizer(mainSizer);

    //création barre du bas
    CreateStatusBar();
    SetStatusText("Bienvenue à RCBanque");
}

AcceuilFrame::~AcceuilFrame() {
	//destructeur
}