#ifndef VIREMENTFRAME_H_INCLUDED
#define VIREMENTFRAME_H_INCLUDED

//include classique
#include "wx/wx.h"
#include "Customer.hpp"
//Definition de notre classe mainFrame
class VirementFrame : public wxFrame
{
public:
	//constructeur
	VirementFrame();
	//destructeur
	~VirementFrame();
	void setActiveClient(client* activeClient);
	wxFrame* centralFrame;
	wxFrame* pastFrame;
private:
	client* m_activeClient;
	wxRadioBox* m_radioBoxVirementLocal;
	wxTextCtrl* m_virementLocalAmmount;

	static const int ID_BTN_VIREMENT_LOCAL;
	//event bouttons click
	void OnButtonVirementLocalClicked(wxCommandEvent& event);

	//tabble des evenements
	DECLARE_EVENT_TABLE();
};

#endif