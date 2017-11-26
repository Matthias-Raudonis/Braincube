/*
Braincube Project:
New esotheric programming language by Matthias Raudonis,
Interpreter and Simulator

MIT License

Copyright (c) 2017 Matthias Raudonis

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#include <stdio.h>
#include "config.h"
#include "functions.h"

uint8_t cube[7][9];
uint8_t pointer;
uint32_t c; // instruction counter
uint32_t c_p; // instruction pointer
uint8_t program[SIZE_PROG];
uint8_t stack[SIZE_STACK];
uint8_t stackp;

int main()
{
    stackp=0;
    c=0;
    c_p=0;
    pointer=1;

    printf("Braincube\n");

    for(int i=1; i<=6; i++)
     {
         for(int j=1; j<=9; j++)
         {
             cube[i][j]=j;
         }
     }


    if(true==compile(".F|F")) printf("Compilation success\n");
    for(int i=0; i<5; i++)
    {
        if(true==execute(1)) printf("\n Execution success\n");
        displayCube();
    }
    return 0;
}
