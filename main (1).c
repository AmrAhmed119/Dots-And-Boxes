#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "colors.h"
#include "mainmenu.h"
#include "comparecharacters.h"
#include "redo.h"
#include "undo.h"
#include "vsComputer.h"
#include "printgame.h"
#include "gameloop.h"
#define MAXSIZE 256

typedef struct         //structure for player
{
    char name[MAXSIZE];
    int moves;
    int score;
    int namelen;
} player;

typedef struct
{
    int score;
    char name[MAXSIZE];
    int namelen;
} user;

int Size;

int main()
{
    system("");

    srand(time(NULL));   //used for computer turn as it generate different random numbers every time


    int i,j,z,m,n;
    int turn=1,moves=0,redomoves=0;
    int winner;   //store the number of the winner
    int scorearray[2]= {0,0};   //store the scores of the players
    player one,two;
    user userarray[MAXSIZE];   //array of structure (used in ranking)

    while(1)
    {

        system("cls");
        user userarray[MAXSIZE]= {0};

        FILE *readrank;           //read Rank file

        readrank =fopen("Rank.bin","rb");

        if(readrank==NULL)
        {
            printf("File is empty");
            readrank = fopen("Rank.bin","rb");
            fclose(readrank);
            readrank = fopen("Rank.bin","rb");
        }

        //read array of structs
        int start=0;
        while(!feof(readrank))   //(feof) tell us have we reached the end of the file or not which returns TRUE or FALSE so we use not
        {
            fread(&userarray[start].namelen, sizeof(int), 1, readrank);
            fread(userarray[start].name,sizeof(char), userarray[start].namelen,readrank);
            userarray[start].name[userarray[start].namelen] = '\0';
            fread(&userarray[start].score, sizeof(int), 1, readrank);
            start++;
        }
        fclose(readrank);

        i = startMenu();

        if(i==1)
        {

            n = difficuilty(j);
            m = mode(z);

            system("cls");

            printf(BBLU"\n\n  Enter your name (Player 1) : "reset);
            fflush(stdin);        //used to clear the stream/buffer, where the program skips the input with spaces so it solves this
            gets(one.name);
            one.namelen = strlen(one.name);

            if(m==2)  //2 players
            {
                system("cls");
                printf(BRED"\n\n  Enter your name (Player 2) : " reset);
                fflush(stdin);
                gets(two.name);
                two.namelen = strlen(two.name);
                system("cls");
            }
            else     //1 player vs cmoputer
            {
                strcpy(two.name,"computer");
                system("cls");
            }


            Size =2*n+2;

            char game[Size][Size];         //Grid
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

            int remMoves = 2*n*(n+1);    //number of remaining lines
            int copygame[remMoves][7];   //for Undo
            int redogame[remMoves][8];   //for Redo

            for(int i=0; i<remMoves; i++)
            {
                for(int j=0; j < 7; j++)
                {
                    copygame[i][j]=0;
                }
            }
            for(int i=0; i<remMoves; i++)
            {
                for(int j=0; j < 8; j++)
                {
                    redogame[i][j]=0;
                }
            }

            one.score=0;
            two.score=0;
            one.moves= 0;
            two.moves = 0;

            // return the winner of the game
            winner = gameloop(n,m,turn,Size, game, one.name,one.namelen, two.name,two.namelen, one.score, two.score, one.moves, two.moves, remMoves,copygame,redogame,moves,redomoves,scorearray);

        }

        if(i==2)
        {
            system("cls");
            int loadNum;
            printf(BYEL"\n  Enter file number (enter 1 , 2 or 3) : "reset);
            scanf("%d",&loadNum);
            if ((loadNum==1) || (loadNum==2) || (loadNum==3))
            {
                char fileName[6];
                sprintf(fileName,"File%d.bin",loadNum);  // sprintf used to store output on char buffer which are specified in sprintf
                FILE *load = fopen(fileName,"rb");
                if(load==NULL)
                {
                    printf("No existing file\n");
                    continue;
                }
                else
                {
                    fseek (load, 0, SEEK_END);
                    int fsize = ftell(load);  //check if file is empty
                    if (fsize == 0)
                    {
                        fclose(load);
                        printf(BYEL"\n  File is empty\n"reset);
                        printf(BYEL"\n  Press Enter to go back or 1 to exit: "reset);
                        fflush(stdin);
                        char enter;
                        scanf("%c",&enter);
                        continue;
                    }
                    else
                    {
                        fclose(load);
                        load = fopen(fileName, "rb");
                    }

                    fread(&n,sizeof(int),1,load);
                    fread(&m,sizeof(int),1,load);

                    int Size = 2*n+2, remMoves = 2*n*(n+1);
                    fread(&remMoves,sizeof(int),1,load);
                    fread(&one.moves,sizeof(int),1,load);
                    fread(&two.moves,sizeof(int),1,load);
                    fread(&one.score,sizeof(int),1,load);
                    fread(&two.score,sizeof(int),1,load);
                    fread(&turn,sizeof(int),1,load);

                    int copygame[remMoves][7];
                    fread(copygame,sizeof(int),remMoves*7,load);  //save Undo data

                    int redogame[remMoves][8];
                    fread(redogame,sizeof(int),remMoves*8,load);  //save Redo data

                    int redomoves;
                    fread(&redomoves,sizeof(int),1,load);

                    int moves;
                    fread(&moves,sizeof(int),1,load);

                    char game[Size][Size];
                    fread(game,sizeof(char),sizeof(game),load);

                   /* int scorearray[2];
                    fread(scorearray,sizeof(int),2,load);*/

                    fread(&one.namelen,sizeof(int),1,load);
                    fread(one.name,sizeof(char),one.namelen,load);
                    one.name[one.namelen] = '\0';
                    if(m==2)              //read player two ifnot computer
                    {
                        fread(&two.namelen,sizeof(int),1,load);
                        fread(two.name,sizeof(char),two.namelen,load);
                        two.name[two.namelen] = '\0';
                    }
                    fclose(load);

                    if(m==1)  //if computer we dont have to read
                    {
                        strcpy(two.name,"computer");
                        two.namelen = strlen(two.name);
                    }

                    winner = gameloop(n,m,turn,Size, game, one.name,one.namelen, two.name,two.namelen, one.score, two.score, one.moves, two.moves, remMoves,copygame,redogame,moves,redomoves,scorearray);
                }
            }
            else
            {
                printf(BYEL"\n  There is no existing file"reset);
                printf(BYEL"\n  Press Enter to go back "reset);
                fflush(stdin);
                char enter;
                scanf("%c",&enter);
            }
        }

        one.score = scorearray[0];
        two.score = scorearray[1];

        if((i==1) || (i==2))  // save data of winner either from starting new game or by loading new game
        {

            if(winner==1)
            {

                int x=0,y=0;

                while(userarray[x].namelen!=0)
                {
                    //check if player has previous score in leaderboard
                    if(strcmp(one.name,userarray[x].name)==0)
                    {
                        y=1;
                        break;
                    }
                    else
                    {
                        x++;
                        if(x==MAXSIZE)  //Refresh Leaderboard after its full of 256 different names
                        {
                            for(int y = 0; y < MAXSIZE; y++)
                            {
                                userarray[y].namelen = 0;
                            }
                            x=0;
                        }
                    }
                }

                if(y==1)   //if player has previous score then choose bigger one
                {
                    if(userarray[x].score<one.score)
                    {
                        userarray[x].score = one.score;
                    }
                }
                else if(y==0)
                {
                    userarray[x].namelen = one.namelen;
                    strcpy(userarray[x].name,one.name);
                    userarray[x].score = one.score;
                }
            }

            else if((winner==2) && (m==2))    //save only winner score for a player not computer
            {
                int x=0,y=0;

                while(userarray[x].namelen!=0)
                {
                    if(strcmp(two.name,userarray[x].name)==0)
                    {
                        y==1;
                        break;
                    }
                    else
                    {
                        x++;
                    }
                }
                if(y==1)
                {
                    userarray[x].score = two.score;
                }
                else if(y==0)
                {
                    userarray[x].namelen = two.namelen;
                    strcpy(userarray[x].name,two.name);
                    userarray[x].score = two.score;
                }
            }

            // write this information into a file to save the rank
            FILE *writerank;
            writerank = fopen("Rank.bin","wb");

            int end=0;

            while((end <MAXSIZE) && (userarray[end].namelen!=0))
            {
                fwrite(&userarray[end].namelen,sizeof(int),1,writerank);
                fwrite(userarray[end].name,sizeof(char),userarray[end].namelen,writerank);
                fwrite(&userarray[end].score,sizeof(int),1,writerank);
                end++;
            }
            fclose(writerank);

            if(winner==1)
            {
                printf(BBLU"\n        Player 1 Wins ....Congratulations\n\t\t\t\t\n\t\t\tGame Ended,hope you enjoyed\n"reset);
                int k;
                printf(BWHT"  Enter 1 to exit:\n  Enter 2 to return to mainmenu:");
                while(1)
                {
                    scanf("%d",&k);
                    if(k==1)
                    {
                        exit(1);
                    }
                    else if(k==2)
                    {
                        break;
                    }
                    else
                    {
                        printf(BWHT"Invalid input,Try again: "reset);

                    }
                }
            }
            else if(winner==2)
            {
                printf(BRED"\n        Player 2 Wins ....Congratulations\n\t\t\t\t\n\t\t\tGame Ended,hope you enjoyed\n"reset);
                printf(BWHT"  Enter 1 to exit:\n  Enter 2 to return to mainmenu:");
                int k;
                scanf("%d",&k);
                while(1)
                {
                    scanf("%d",&k);
                    if(k==1)
                    {
                        exit(1);
                    }
                    else if(k==2)
                    {
                        break;
                    }
                    else
                    {
                        printf(BWHT"Invalid input,Try again: "reset);

                    }
                }
            }
            else if(winner==3)
            {
                printf(BYEL"\n        Tie game\n\t\t\t\tGame Ended,hope you enjoyed\n"reset);
                printf(BWHT"  Enter 1 to exit:\n  Enter 2 to return to mainmenu:"reset);
                int k;
                while(1)
                {
                    scanf("%d",&k);
                    if(k==1)
                    {
                        exit(1);
                    }
                    else if(k==2)
                    {
                        break;
                    }
                    else
                    {
                        printf(BWHT"Invalid input,Try again: "reset);

                    }
                }
            }

        }
        if(i==3)  //leaderboard
        {
            system("cls");

            int i, j;
            user temp;
            for(i = 0; i < MAXSIZE-1; i++)
            {
                for(j = 0; j < MAXSIZE-1-i; j++)
                    if(userarray[j].score < userarray[j+1].score)  //descending order
                    {
                        temp = userarray[j];
                        userarray[j] = userarray[j+1];
                        userarray[j+1] = temp;
                    }
            }

            for(i=0; i<10; i++)
            {
                printf("\n\t%d-",i+1);
                for(j=0; userarray[i].name[j]!='\0'; j++)
                {
                    printf(BWHT"%c"reset,userarray[i].name[j]);
                }
                printf(BWHT"  --> %d\n"reset,userarray[i].score);
            }
            printf(BYEL"\n\tPress enter to go back"reset);
            char enter;
            fflush(stdin);
            scanf("%c",&enter);
        }
        if(i==4)  //End Game
        {
            exit(1);          //return 0;
        }

    }
    return 0;
}
