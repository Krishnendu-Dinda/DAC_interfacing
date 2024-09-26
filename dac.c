
/////////////////////////// DAC INTERFACING //////////////////////////////
#include<reg51.h>
#define DATA P2


unsigned int k,i;
signed int j;
unsigned int sin_valu[]={128,139,161,182,201,219,233,244,252,255,255,252,244,233,219,201,182,161,139,117,
													95,74,55,37,23,12,4,0,2,4,12,23,37,55,74,95,117,128};

void delay(unsigned int x){
	for(j=0;j<x;j++)
		for(k=0;k<1275;k++);	

}

void delay_mS(){  //  Create a delay of 50mS.
  TMOD=0X01;   // Declear TMOD Resister as Timer 0 Mode 1.
	TH0=0x4B;		 // Load 4B to the TH0 resister.
	TL0=0xFD;		// Load FD to the TL0 resister.
	TR0=1;			//Start Timer 0 resister.
	 while(TF0==0);  // Check if timer 0 is overflow or not.
	 TR0=0;					//Stop Timer 0 resister.
	 TF0=0;					//Reset Timer 0 Overflow flag.
 }

int main(){
P1=0xFF;
	while(1){	
	//************************************************************//
			if(P1==0xFE){					//Sine wave
			for(i=0;i<38;i++){		 
			P2=sin_valu[i];	
			delay(1);
		}
			
	}	
	//***********************************************************//
			if(P1==0xFD){				//Squre wave
				P2=0xFF;
				delay_mS();
				P2=0x00;
				delay_mS();
			}
	//***********************************************************//		
				if(P1==0xFB){						//Swatooth wave
					
	//	delay(1);					
		for(k=0;k<255;k++){
		
				P2=k;
		}
		P2=0;
	}	
	//*************************************************************//		
	if(P1==0xF7){									//Triangular wave
		for(j=0;j<255;j++){
		
				P2=j;
		}
			for(j=255;j>0;j--){
		
				P2=j;
		}
	}
		
	}
}
