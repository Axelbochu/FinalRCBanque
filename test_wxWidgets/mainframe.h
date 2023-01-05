#ifndef MAINFRAME_H_INCLUDED
#define MAINFRAME_H_INCLUDED

//include classique
#include "wx/wx.h"
#include "Customer.hpp"
#include <vector>
//Definition de notre classe mainFrame
class MainFrame : public wxFrame
{
public:
	//constructeur
	MainFrame(client* actualClientConstructeur);
	//destructeur
	~MainFrame();

	wxFrame* m_frame;

	void setActualClient(client* actualClient);
private:
	client* actualClient; //stock le client actuel
	//pointeur vers les montants d'argents
	wxStaticText* soldeDepot, *epargneMtn;
	//identifiants boutons
	static const int ID_BTN_DEPOT, ID_BTN_EPARGNE, ID_BTN_VIREMENT;

	//event bouttons click
	void OnButtonDepotClicked(wxCommandEvent& event);
	void OnButtonEpargneClicked(wxCommandEvent& event);
	void OnButtonVirementClicked(wxCommandEvent& event);

	//tabble des evenements
	DECLARE_EVENT_TABLE();
};

#endif