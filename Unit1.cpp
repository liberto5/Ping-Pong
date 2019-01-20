//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "mmsystem.h"

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

        double x = -4;
        double y = -4;
        int acceleration = 0;
        int bounces = 0;
        int pointsLeft = 0;
        int pointsRight = 0;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        AnsiString welcomeMessage = "Witaj w grze PingPong.";
        AnsiString controllingInstructions1 = "Lewy gracz steruje wciskaj¹c klawisze A oraz Z.";
        AnsiString controllingInstructions2 = "Prawy gracz steruje wciskaj¹c strza³ki do góry i w dó³.";
        AnsiString additionalInformation1 = "Dla urozmaicenia zabawy:";
        AnsiString additionalInformation2 = "Kiedy odbijesz pi³kê na œrosku paletki ";
        AnsiString additionalInformation3 = "wówczas zmienisz jej k¹t odbicia i pi³ka przyœpieszy.";
        AnsiString additionalInformation4 = "Im d³u¿ej odbijasz, tym pi³ka szybciej przemieszcza siê.";
        AnsiString additionalInformation5 = "Mo¿esz dowolnie zmieniaæ pole gry.";
        AnsiString haveFunMessage = "Mi³ej zabawy!";
        ShowMessage (welcomeMessage + sLineBreak + sLineBreak + controllingInstructions1 + sLineBreak +
        controllingInstructions2 + sLineBreak + sLineBreak + additionalInformation1 + sLineBreak +
        additionalInformation2 + additionalInformation3 + sLineBreak + additionalInformation4 +
        sLineBreak + additionalInformation5 + sLineBreak + sLineBreak + haveFunMessage);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::timerBallTimer(TObject *Sender)
{
        newGame->Visible = false;
        nextRound->Visible = false;
        Form1->pointLeft->Caption = "";
        Form1->pointRight->Caption = "";
        Form1->score->Caption = "";
        Form1->hits->Caption = "";
        paddleLeft->Left = background->Left + 20;
        paddleRight->Left = background->Left + background->Width - 38;
        newGame->Left = background->Width / 2 - newGame->Width / 2;
        nextRound->Left = background->Width / 2 - nextRound->Width / 2;

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
                if (ball->Top > paddleLeft->Top + 65 &&
                    ball->Top + ball->Height < paddleLeft->Top + paddleLeft->Height -65)
                    {
                        x *= 1.1;
                        y *= 1.1;
                    }
                acceleration++;
                bounces++;
            }

        //bounce from right paddle
        if (ball->Top > paddleRight->Top - ball->Height/2 &&
            ball->Top + ball->Height < paddleRight->Top + paddleRight->Height + ball->Height/2 &&
            ball->Left + ball->Width > paddleRight->Left)
            {
                if (x>0) x = -x;
                if (ball->Top > paddleRight->Top + 65 &&
                    ball->Top + ball->Height < paddleRight->Top + paddleRight->Height -65)
                    {
                       x *= 1.1;
                       y *= 1.08;
                    }
                acceleration++;
                bounces++;
            }

        //point for right user
        if (ball->Left < paddleLeft->Left + paddleLeft->Width - 10 )
        {
                pointsRight++;
                Form1->pointLeft->Caption = "Punkt dla gracza prawego >>>";
        }

        //point for left user
        if (ball->Left + ball->Width > paddleRight->Left + 10 )
        {
                pointsLeft++;
                Form1->pointLeft->Caption = "<<< Punkt dla gracza lewego";
        }

        if ((ball->Left < paddleLeft->Left + paddleLeft->Width - 10) ||
        (ball->Left + ball->Width > paddleRight->Left + 10 ))
        {
                timerBall->Enabled = false;
                ball->Visible = false;
                AnsiString pointsRightAsAString = IntToStr (pointsRight);
                AnsiString pointsLeftAsAString = IntToStr (pointsLeft);
                AnsiString bouncesAsAString = IntToStr (bounces);
                Form1->score->Caption = pointsLeftAsAString + ":" + pointsRightAsAString;
                Form1->hits->Caption = "Iloœæ odbiæ: " + bouncesAsAString;
                nextRound->Visible = true;
                newGame->Visible = true;
                pointLeft->Left = background->Width / 2 - pointLeft->Width / 2;
                pointRight->Left = background->Width / 2 - pointRight->Width / 2;
                score->Left = background->Width / 2 - score->Width / 2;
                hits->Left = background->Width / 2 - hits->Width / 2;
                ball->Left = background->Width / 2;
        }

        //accelerate ball
        if (acceleration == 5)
        {
                x *= 1.1;
                y *= 1.1;
                acceleration = 0;
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
void __fastcall TForm1::newGameClick(TObject *Sender)
{
        acceleration = 0;
        bounces = 0;
        pointsLeft = 0;
        pointsRight = 0;
        x = -4;
        y = -4;
        ball->Visible = true;
        timerBall->Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::nextRoundClick(TObject *Sender)
{
        acceleration = 0;
        bounces = 0;
        x = -x;
        ball->Visible = true;
        timerBall->Enabled = true;
}
//---------------------------------------------------------------------------


