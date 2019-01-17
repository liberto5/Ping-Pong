//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *background;
        TImage *ball;
        TTimer *timerBall;
        TImage *paddleLeft;
        TImage *paddleRight;
        TTimer *leftPaddleUp;
        TTimer *leftPaddleDown;
        TTimer *rightPaddleUp;
        TTimer *rightPaddleDown;
        void __fastcall timerBallTimer(TObject *Sender);
        void __fastcall leftPaddleUpTimer(TObject *Sender);
        void __fastcall leftPaddleDownTimer(TObject *Sender);
        void __fastcall rightPaddleUpTimer(TObject *Sender);
        void __fastcall rightPaddleDownTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
