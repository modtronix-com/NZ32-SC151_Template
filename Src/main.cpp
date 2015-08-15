// This is a very simple demo program for the Modtronix NZ32-Sxx range of boards, like the
// NZ32-SC151, NZ32-SB072, NZ32-SE411.... It blinks the system LED. If the system button
// is pressed, the LED stays on permanently. Additionally it outputs a "Hello World" message
// to the default serial port. Available via USB Com port when using PGM-NUCLEO programmer.
//
// This demo contains the full mbed API, enabling very easy software development. For detail, see:
// https://developer.mbed.org/handbook/Homepage
//
// For details on the NZ32-SC151 board, see:
// http://wiki.modtronix.com/doku.php?id=products:nz-stm32:nz32-sc151
//
// This demo can be used with the free CoIDE(from coocox) or SW4STM32(System Workbench for STM32)
// IDEs. Both are free, and use the free GNU ARM GCC C/C++ compilers.
//
// For details how to build this project, debug and program the target board using CoIDE, see:
// http://wiki.modtronix.com/doku.php?id=tutorials:coide-with-nz32-boards
//
// For details how to build this project, debug and program the target board using SW4STM32, see:
// http://wiki.modtronix.com/doku.php?id=tutorials:sw4stm32-with-nz32-boards
#include "mbed.h"

DigitalOut  myled(LED1);
DigitalIn   myButton(USER_BUTTON);
Serial      pc(USBTX, USBRX);   //Use default TX and RX. Available via USB Com port when using PGM-NUCLEO programmer

int main() {
    pc.printf("Hello World");   // Write to default UART. Available via USB Com port when using PGM-NUCLEO programmer

    //Endless while loop
    while(1) {
        myled = 1;          // LED is ON
        wait_ms(200);       // 200 ms
        myled = 0;          // LED is OFF
        wait_ms(500);       // 500 ms

        //As long as button is pressed, turn LED on
        while(myButton == 1) {
            myled = 1;      // LED is ON
        }
    }
}
