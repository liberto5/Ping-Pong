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

        //bounce from left paddle
        if (ball->Top > paddleLeft->Top - ball->Height/2 &&
            ball->Top + ball->Height < paddleLeft->Top + paddleLeft->Height + ball->Height/2 &&
            ball->Left < paddleLeft->Left + paddleLeft->Width)
            {
                if (x<0) x = -x;
            }

        //bounce from right paddle
        if (ball->Top > paddleRight->Top - ball->Height/2 &&
            ball->Top + ball->Height < paddleRight->Top + paddleRight->Height + ball->Height/2 &&
            ball->Left + ball->Width > paddleRight->Left)
            {
                if (x>0) x = -x;
            }


        //point for right user
        if (ball->Left < paddleLeft->Left + paddleLeft->Width -10 )
        {
                timerBall->Enabled = false;
                ball->Visible = false;
        }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::leftPaddleUpTimer(TObject *Sender)
{
        if (paddleLeft->Top > 10) paddleLeft->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::leftPaddleDownTimer(TObject *Sender)
{
        if (paddleLeft->Top + paddleLeft->Height < background->Height -10 ) paddleLeft->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rightPaddleUpTimer(TObject *Sender)
{
        if (paddleRight->Top > 10) paddleRight->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rightPaddleDownTimer(TObject *Sender)
{
        if (paddleRight->Top + paddleRight->Height < background->Height -10 ) paddleRight->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == 'A') leftPaddleUp->Enabled = true;
        if (Key == 'Z') leftPaddleDown->Enabled = true;
        if (Key == VK_UP) rightPaddleUp->Enabled = true;
        if (Key == VK_DOWN) rightPaddleDown->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == 'A') leftPaddleUp->Enabled = false;
        if (Key == 'Z') leftPaddleDown->Enabled = false;
        if (Key == VK_UP) rightPaddleUp->Enabled = false;
        if (Key == VK_DOWN) rightPaddleDown->Enabled = false;
}
//---------------------------------------------------------------------------

