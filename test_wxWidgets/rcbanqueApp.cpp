#include "rcbanqueApp.h"
#include "mainFrame.h"
#include "acceuilFrame.hpp"
#include "inscriptionFrame.h"
#include "Customer.hpp"
#include <string>

client* actualClient;
//definitiion onInit
bool rcBanqueApp::OnInit()
{
	//on créer un objet mainFrame
	MainFrame* frame = new MainFrame();
	//on l'affiche
	frame->Show();
	//indique que l'application peut continuer 
	return true;
}

IMPLEMENT_APP(rcBanqueApp);
