#include <wx/filename.h>
#include <wx/stdpaths.h>
#include "Character.h"
#include "Tetris.h"
#include "IniWindow.h"
#include "Hamtaro.h"
#include "Elizabeth.h"
#include "Pikachu.h"

BEGIN_EVENT_TABLE(Character, wxPanel)
	EVT_PAINT(Character::OnPaint)
	EVT_BUTTON(1003, Character::HamtaroButton)
	EVT_BUTTON(1004, Character::PikachuButton)
	EVT_BUTTON(1005, Character::ElizabethButton)
END_EVENT_TABLE()

Character::Character(wxWindow *window, wxSize panelSize, wxFrame *parent) :
	wxPanel(window, wxID_ANY, wxPoint(0, 0), panelSize, wxBORDER_NONE)
{
	pFrame = (Tetris*)parent;
	pWindow = (IniWindow*)window;

	this->SetBackgroundColour(wxColour(*wxWHITE));

	//load image
	this->LoadCharMenuBG();
	this->LoadCharButtons();

	//memunculkan buttons
	wxBitmapButton* ElizabethButton = new wxBitmapButton(this, 1005, *elizabethB, wxPoint(59, 344));
	wxBitmapButton* PikachuButton = new wxBitmapButton(this, 1004, *pikachuB, wxPoint(304, 344));
	wxBitmapButton* HamtaroButton = new wxBitmapButton(this, 1003, *hamtaroB, wxPoint(550, 344));
}

Character::~Character()
{
	delete charmenuBG;
	delete hamtaroB;
	delete pikachuB;
	delete elizabethB;
	delete board;
}

void Character::LoadCharMenuBG()
{
	wxImage charMenuImage(wxT("CharMenu.jpg"), wxBITMAP_TYPE_JPEG);
	charmenuBG = new wxBitmap(charMenuImage);
}

void Character::LoadCharButtons()
{
	wxImage hamtaroImage(wxT("HamtaroButton.jpg"), wxBITMAP_TYPE_JPEG);
	hamtaroB = new wxBitmap(hamtaroImage);
	wxImage pikachuImage(wxT("PikachuButton.jpg"), wxBITMAP_TYPE_JPEG);
	pikachuB = new wxBitmap(pikachuImage);
	wxImage elizabethImage(wxT("ElizabethButton.jpg"), wxBITMAP_TYPE_JPEG);
	elizabethB = new wxBitmap(elizabethImage);
}

void Character::OnPaint(wxPaintEvent & event)
{
	wxPaintDC pdc(this);
	if (charmenuBG != nullptr)
	{
		pdc.DrawBitmap(*charmenuBG, wxPoint(0, 0), true);
	}
}

void Character::ElizabethButton(wxCommandEvent & event)
{
	board = new Elizabeth(pWindow, wxSize(410, 902), pFrame);
	board->SetPosition(wxPoint(0, 0));
	pWindow->ShowGame((Board*)board);
}

void Character::PikachuButton(wxCommandEvent & event)
{
	board = new Pikachu(pWindow, wxSize(410, 902), pFrame);
	board->SetPosition(wxPoint(0, 0));
	pWindow->ShowGame((Board*)board);
}

void Character::HamtaroButton(wxCommandEvent & event)
{
	board = new Hamtaro(pWindow, wxSize(410, 902), pFrame);
	board->SetPosition(wxPoint(0, 0));
	pWindow->ShowGame((Board*)board);
}

