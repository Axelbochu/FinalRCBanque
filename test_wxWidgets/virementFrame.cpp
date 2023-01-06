#include "virementFrame.hpp"
#include "Customer.hpp"
#include "Customer_for_JSON.hpp"
#include "mainframe.h"
#include <string>

//on affecte les identifiants aux boutons
const int VirementFrame::ID_BTN_VIREMENT_LOCAL = wxNewId();
//Definition de la table des evenements
BEGIN_EVENT_TABLE(VirementFrame, wxFrame)
    EVT_BUTTON(ID_BTN_VIREMENT_LOCAL, VirementFrame::OnButtonVirementLocalClicked)
END_EVENT_TABLE()


VirementFrame::VirementFrame() :wxFrame(NULL, wxID_ANY, _T("RCBanque")) {
    wxPanel* panel = new wxPanel(this, -1);
    
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

        wxStaticBoxSizer* localVirementBox = new wxStaticBoxSizer(wxVERTICAL, panel, _T("Faire un virement local :"));
            
            wxArrayString choicesVirementLocal;
            choicesVirementLocal.Add("compte DEPOT vers compte EPARGNE");
            choicesVirementLocal.Add("compte EPARGNE vers compte DEPOT");
            m_radioBoxVirementLocal = new wxRadioBox(panel, wxID_ANY, _T("Quel type de virement ? :"), wxDefaultPosition, wxDefaultSize, choicesVirementLocal, 2, wxRA_VERTICAL);
            localVirementBox->Add(m_radioBoxVirementLocal, 0, wxALL, 5);

            wxStaticText* labelFondVirement = new wxStaticText(panel, -1, _T("Montant du virement :"));
            localVirementBox->Add(labelFondVirement, 0, wxTOP | wxLEFT | wxRIGHT | wxEXPAND, 5);
            m_virementLocalAmmount = new wxTextCtrl(panel, -1, _T(""));
            localVirementBox->Add(m_virementLocalAmmount, 0, wxBOTTOM | wxLEFT | wxRIGHT | wxEXPAND, 5);

            wxButton* localViremntBtn = new wxButton(panel, ID_BTN_VIREMENT_LOCAL, _T("Envoyer..."));
            localVirementBox->Add(localViremntBtn, wxALL, 10);

        mainSizer->Add(localVirementBox, 0, wxEXPAND|wxALL,10);

    panel->SetSizer(mainSizer);
    mainSizer->SetSizeHints(this);
}

VirementFrame::~VirementFrame() {
    //Destructeur
}

void VirementFrame::setActiveClient(client* activeClient) {
    this->m_activeClient = activeClient;
}

void VirementFrame::OnButtonVirementLocalClicked(wxCommandEvent& event) {
    //virement courant vers epargne
    if (m_radioBoxVirementLocal->GetSelection() == 0) {
        courant_to_epargne(m_activeClient, wxAtoi(m_virementLocalAmmount->GetValue()));
        wxMessageBox(_T("Virement réalisé avec succès !"));
        MainFrame* frame = new MainFrame(m_activeClient);
        frame->Show();
        frame->m_frame = frame;
    }
    else if (m_radioBoxVirementLocal->GetSelection() == 1) {
        epargne_to_courant(m_activeClient, wxAtoi(m_virementLocalAmmount->GetValue()));
        wxMessageBox(_T("Virement réalisé avec succès !"));
        MainFrame* frame = new MainFrame(m_activeClient);
        frame->Show();
        frame->m_frame = frame;
    }
    centralFrame->Destroy();
    pastFrame->Destroy();
}