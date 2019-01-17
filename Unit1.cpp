//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

        int x = -8;
        int y = -8;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::timerBallTimer(TObject *Sender)
{
        ball->Left += x;
        ball->Top += y;

        //bounce a ball from a top wall
        if (ball->Top + 5 <= background->Top) y = -y;

        //bounce a ball from a bottom wall
        if ((ball->Top + ball->Height + 5) >= background->Height) y = -y;

        //point for right user
        if (ball->Left < paddleLeft->Left + paddleLeft->Width +10)
        {
                timerBall->Enabled = false;
                ball->Visible = false;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::leftPaddleUpTimer(TObject *Sender)
{
        paddleLeft->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::leftPaddleDownTimer(TObject *Sender)
{
        paddleLeft->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rightPaddleUpTimer(TObject *Sender)
{
        paddleRight->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rightPaddleDownTimer(TObject *Sender)
{
        paddleRight->Top -= 10;
}
//---------------------------------------------------------------------------

