#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "colors.h"
#include "mainmenu.h"
#include "comparecharacters.h"
#include "vsComputer.h"
#include "printgame.h"
#include "gameloop.h"
#define MAXSIZE 256

int Size;
int main()
{
    system("");
    system("cls");

    srand(time(NULL));

    int i,j,z,m,n;

    typedef struct
    {
        char name[MAXSIZE];
        int moves;
        int score;
        int namelen;
    } player;

    player one,two;

    i = startMenu();

    if(i==1)
    {

        n = difficuilty(j);
        m = mode(z);

        system("cls");

        printf(BBLU"\n\n  Enter your name (Player 1),Enter one name without spaces : "reset);
        scanf("%s",one.name);
        one.namelen = strlen(one.name);

        if(m==2)
        {
            system("cls");
            printf(BRED"\n\n  Enter your name (Player 2),Enter one name without spaces : " reset);
            scanf("%s",two.name);
            two.namelen = strlen(two.name);
            system("cls");
        }
        else
        {
            strcpy(two.name,"computer");
            system("cls");
        }
    }

    Size =2*n+2;

    char game[Size][Size];
    for(int j=0; j < Size; j++)
    {
        game[0][j] = j;
        game[j][0] = j;
        if(j%2 != 0)
        {
            for(int i=1; i < Size; i=i+2)
            {
                game[i][j] = 254;
                if(i!=Size-1)
                {
                    game[i+1][j] =' ';
                }
            }
        }
        else if(j%2 == 0)
        {
            for(int i=1; i < Size; i = i+2)
            {
                game[i][j] =' ';
                if(i!=Size-1)
                {
                    game[i+1][j] =' ';
                }
            }
        }
    }

    int remMoves = 2*n*(n+1);
    one.score=0;
    two.score=0;
    one.moves= 0;
    two.moves = 0;

    gameloop(n,m,Size, game, one.name, two.name, one.score, two.score, one.moves, two.moves, remMoves);


    if(i==2)
    {

    }
    if(i==3)
    {

    }
    if(i==4)  //End Game
    {
        return 0;
    }


    return 0;
}
