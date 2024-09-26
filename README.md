# DAC_interfacing
<br>
In this post I share my next work which is interfacing a DAC ic with AT89C51 [8051] microcontroller .
Here the formula for generate sine wave [Vo=5V+(5*sinθ)]. To find sine wave , value sent to the DAC various angles ,we use the formula, DAC value=(Vo*25.6). We multiply 25.6 because there are 256 step and full scale Vout is 10volt. Therefore , (256 steps/10V)=25.6 step per volt.
<br>
For square wave Generate, we simply sent DAC input is FFH  & stay this state 50mS . And after that sent 00H &  stay this state 50mS. So, the full cycle is 100mS.
<br>
For sawtooth wave, we sent the value 00H  to  FFH increase one by one value & when reach FFH then sent 00H. So, the wave is generated sawtooth wave.
<br>
For Triangular wave, we sent the value 00H to FFH increase one by one value. When the value reach FFH then the value decrease one by one from
FFH to 00H .In this process a triangular wave Generated.  

<br>
When Microcontroller are used like measuring and control of physical quantity like temperature, pressure, speed, etc. 
<br>
This systems microcontroller generates output which is in digital form but the controlling system requires analog signal as they don't accept digital data thus making it necessary to use DAC which converts digital data into equivalent analog voltage.
<br>
we use 8-bit DAC 0808. This IC converts digital data into equivalent analog Current. DAC 0808 IC output current is calculated by formula below  :- 
	Io = Vref/R14 * (A1/2 + A2/4 + A3/8 + A4/16 + A5/32 + A6/64 + A7/128 + A8/256)
<br>
In DAC 0808 IC Output we get the current but we require voltage to the output . So, we use I to V converter & use this formula [Vo = Io * Rf ] to convert current output to the voltage .
<br>
Here we calculate the maximum output voltage :-
<br>
Rf = 5 K , then Vo (max) = 2 mA * 5 K = 10 
<br>
Ex:-
<br>
(1). If binary input A1 A2 A3 A4 A5 A6 A7 A8 = 00000000, then 
<br>
Io = 5/5K * (0/2 + 0/4 + 0/8 + 0/16 + 0/32 + 0/64 + 0/128 +0/256) 
<br>
Io = 5/5K * (0) ~ 0mA
<br>
HexValue    Iout         Io * Rf         Vout  
<br>
     00H        0 mA     0 mA* 5k      0 V
<br>
(2).If binary input A1 A2 A3 A4 A5 A6 A7 A8 = 11111111, then Io = 5/5K * (1/2 + 1/4 + 1/8 + 1/16 + 1/32 + 1/64 + 1/128 + 1/256) Io = 5/5K * (255/256) ~ 2 mA
<br>
HexValue    Iout        Io * Rf           Vout  
    <br>
     FFH         2mA      2mA * 5k       10 V
