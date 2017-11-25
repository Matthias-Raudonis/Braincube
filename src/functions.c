/*
Braincube Project:
New esotheric programming language by Matthias Raudonis,
Interpreter and Simulator

MIT License

Copyright (c) 2017 Matthias-Raudonis

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

extern uint8_t cube[6][9];
extern uint8_t pointer;

enum {
    incP,
    decP,
    incV,
    decV,
    oput,
    iput,
    negL,
    JmpF,
    JmpB,
    L_Front,
    L_Back,
    L_Up,
    L_Down,
    L_Right,
    L_Left,
};

bool compile(uint8_t *program, char *text)
{
    uint32_t c=0;    // instruction counter

    while(*text)
    {
        switch(*text)
        {
        case '+':
            program[c++]=incV;
            break;
        case '-':
            program[c++]=decV;
            break;
        case '>':
            program[c++]=incP;
            break;
        case '<':
            program[c++]=decP;
            break;

        default:
            break;


        }
    }
}


void displayCube()
{
// surface:
// 123
// 456
// 789
//CUBE Orientation
//  1
// 2345
//  6
    char buffer [100];
    char* buf = buffer;
    for (int i=0; i<GUI_fspaces; i++) buf+=sprintf(buf," ");
    char* buf_beg = buf;


    buf+=sprintf(buf,"        x - - - x");
    buf+=sprintf(buf,"\n");
    printf("%s",buffer);

    buf=buf_beg;
    buf+=sprintf(buf,"        | %i %i %i |",cube[1][1],cube[1][2],cube[1][3]);
    buf+=sprintf(buf,"\n");
    printf("%s",buffer);

    buf=buf_beg;
    buf+=sprintf(buf,"        | %i %i %i |",cube[1][4],cube[1][5],cube[1][6]);
    buf+=sprintf(buf,"\n");
    printf("%s",buffer);

    buf=buf_beg;
    buf+=sprintf(buf,"        | %i %i %i |",cube[1][7],cube[1][8],cube[1][9]);
    buf+=sprintf(buf,"\n");
    printf("%s",buffer);

    buf=buf_beg;
    buf+=sprintf(buf,"x - - - x-------x - - - x - - - x");
    buf+=sprintf(buf,"\n");
    printf("%s",buffer);


    for(int j=1; j<=9; j+=3)
    {
        buf=buf_beg;
        for(int i=2; i<=5; i++)
        {
            buf+=sprintf(buf,"| %i %i %i ",cube[i][j],cube[i][j+1],cube[i][j+2]);
        }
        buf+=sprintf(buf,"|\n");
        printf("%s",buffer);
    }

    buf=buf_beg;
    buf+=sprintf(buf,"x - - - x-------x - - - x - - - x");
    buf+=sprintf(buf,"\n");
    printf("%s",buffer);

    buf=buf_beg;
    buf+=sprintf(buf,"        | %i %i %i |",cube[6][1],cube[6][2],cube[6][3]);
    buf+=sprintf(buf,"\n");
    printf("%s",buffer);

    buf=buf_beg;
    buf+=sprintf(buf,"        | %i %i %i |",cube[6][4],cube[6][5],cube[6][6]);
    buf+=sprintf(buf,"\n");
    printf("%s",buffer);

    buf=buf_beg;
    buf+=sprintf(buf,"        | %i %i %i |",cube[6][7],cube[6][8],cube[6][9]);
    buf+=sprintf(buf,"\n");
    printf("%s",buffer);

    buf=buf_beg;
    buf+=sprintf(buf,"        x - - - x");
    buf+=sprintf(buf,"\n");
    printf("%s",buffer);
}