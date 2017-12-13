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
uint32_t program[SIZE_PROG][2];
uint32_t stack[SIZE_STACK];
uint32_t stackp;

int main(int argc, const char * argv[])
{
    FILE *fp;
    stackp=0;
    c_p=0;
    pointer=1;
    uint32_t count=0;
    uint8_t input[SIZE_PROG];


    printf("Braincube Interpreter v. 0.1\n");
    printf("%s\n",argv[1]);
    if (argc >= 1 || (fp = fopen(argv[1], "r")) == NULL)
    {
        displayCube();
        printf("No input file");
        return 1;
    }

    while ((input[count++] = getc(fp)) != EOF)

        for(int i=1; i<=6; i++)
        {
            for(int j=1; j<=9; j++)
            {
                cube[i][j]=i;
            }
        }


    if(true==compile(input)) printf("Compilation success\n");
    displayCube();
    if(true==execute(100)) printf("\n Execution success\n");
    displayCube();


    /*for(int i=0; i<5; i++)
    {
        if(true==execute(1)) printf("\n Execution success\n");
        displayCube();
    }*/
    return 0;
}
