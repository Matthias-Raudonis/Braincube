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

extern uint8_t cube[6][9];
extern uint8_t pointer;

extern uint32_t c;    // instruction counter
extern uint32_t c_p;    // instruction pointer
extern uint32_t program[SIZE_PROG][2];
extern uint32_t stack[SIZE_STACK];
extern uint32_t stackp;
enum
{
    null=0,
    incP,
    decP,
    incV,
    decV,
    oput,
    iput,

    L_Front,    // mixing N and L necessary because of +1
    N_Front,
    L_Back,
    N_Back,
    L_Up,
    N_Up,
    L_Down,
    N_Down,
    L_Right,
    N_Right,
    L_Left,
    N_Left,

    JmpF,
    JmpB,
};

bool compile(char *text)
{

    bool negflag = false;
    while(*text)
    {
        switch(*text)
        {
        case '+':
            program[c++][0]=incV;
            negflag=0;
            break;
        case '-':
            program[c++][0]=decV;
            negflag=0;
            break;
        case '>':
            program[c++][0]=incP;
            negflag=0;
            break;
        case '<':
            program[c++][0]=decP;
            negflag=0;
            break;
        case '.':
            program[c++][0]=oput;
            negflag=0;
            break;
        case ',':
            program[c++][0]=iput;
            negflag=0;
            break;
        case '|':
            negflag=1;
            break;
        case 'F':
            program[c++][0]=L_Front+negflag;
            negflag=0;
            break;
        case 'B':
            program[c++][0]=L_Back+negflag;
            negflag=0;
            break;
        case 'U':
            program[c++][0]=L_Up+negflag;
            negflag=0;
            break;
        case 'D':
            program[c++][0]=L_Down+negflag;
            negflag=0;
            break;
        case 'R':
            program[c++][0]=L_Right+negflag;
            negflag=0;
            break;
        case 'L':
            program[c++][0]=L_Left+negflag;
            negflag=0;
            break;
        case '[':
            program[c++][0]=JmpF;
            negflag=0;
            if(stackp==SIZE_STACK-1) return false;
            stack[stackp++] = c;
            break;
        case ']':
            program[c][0]=JmpB;
            negflag=0;
            if(stackp==0) return false;

            program[c][1]=stack[--stackp];
            program[stack[stackp]][1]= c;
            c++;
            break;


        default:
            break;

        }
        (text++);
    }
    if(stackp) return false;
    return true;
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


    buf+=sprintf(buf,"P:%i(%X)  x - - - x",pointer,cube[3][pointer]);
    buf+=sprintf(buf,"\n");
    printf("%s",buffer);

    buf=buf_beg;
    buf+=sprintf(buf,"        | %X %X %X |",cube[1][1],cube[1][2],cube[1][3]);
    buf+=sprintf(buf,"\n");
    printf("%s",buffer);

    buf=buf_beg;
    buf+=sprintf(buf,"        | %X %X %X |",cube[1][4],cube[1][5],cube[1][6]);
    buf+=sprintf(buf,"\n");
    printf("%s",buffer);

    buf=buf_beg;
    buf+=sprintf(buf,"        | %X %X %X |",cube[1][7],cube[1][8],cube[1][9]);
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
            buf+=sprintf(buf,"| %X %X %X ",cube[i][j],cube[i][j+1],cube[i][j+2]);
        }
        buf+=sprintf(buf,"|\n");
        printf("%s",buffer);
    }

    buf=buf_beg;
    buf+=sprintf(buf,"x - - - x-------x - - - x - - - x");
    buf+=sprintf(buf,"\n");
    printf("%s",buffer);

    buf=buf_beg;
    buf+=sprintf(buf,"        | %X %X %X |",cube[6][1],cube[6][2],cube[6][3]);
    buf+=sprintf(buf,"\n");
    printf("%s",buffer);

    buf=buf_beg;
    buf+=sprintf(buf,"        | %X %X %X |",cube[6][4],cube[6][5],cube[6][6]);
    buf+=sprintf(buf,"\n");
    printf("%s",buffer);

    buf=buf_beg;
    buf+=sprintf(buf,"        | %X %X %X |",cube[6][7],cube[6][8],cube[6][9]);
    buf+=sprintf(buf,"\n");
    printf("%s",buffer);

    buf=buf_beg;
    buf+=sprintf(buf,"        x - - - x");
    buf+=sprintf(buf,"\n");
    printf("%s",buffer);
}


bool execute(uint32_t number)
{

    while(number--&&c>=c_p)
    {
        switch(program[c_p][0])
        {
        case incP:
            if(pointer>=9) pointer=1;
            else pointer++;
            break;
        case decP:
            if(pointer<=1) pointer=9;
            else pointer--;
            break;
        case incV:
            if((cube[3][(uint32_t)pointer])>=MAXNUMBER) (cube[3][(uint32_t)pointer])=0;
            else (cube[3][(uint32_t)pointer])++;
            break;
        case decV:
            if((cube[3][(uint32_t)pointer])<1) (cube[3][(uint32_t)pointer])=MAXNUMBER;
            else (cube[3][(uint32_t)pointer])--;
            break;
        case oput:
            printf("%X",(uint32_t)cube[3][(uint32_t)pointer]);
            break;
        case iput:
            printf("input:");
            scanf("%X",(uint32_t*)(&cube[3][(uint32_t)pointer]));
            break;
        case JmpF:

            if(!cube[3][(uint32_t)pointer])
            {
#ifdef DEBUG_M
                printf("JmpF from %i to %i",c_p,program[c_p][1]);
#endif // DEBUG
            }
            c_p=program[c_p][1];
            break;
        case JmpB:

            if(cube[3][(uint32_t)pointer])
            {
#ifdef DEBUG_M
                printf("JmpB from %i to %i",c_p,program[c_p][1]);
#endif // DEBUG
                c_p=program[c_p][1];
            }
            break;
        default:
            return false;
            break;

        }
        c_p++;




    }
    return true;
}
