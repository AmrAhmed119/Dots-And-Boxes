void printGame(int invalid,int Size,char game[Size][Size],char name1[],char name2[],int score1,int score2,int moves1,int moves2,int remMoves,int turn,clock_t t1,clock_t t2,int undo)
{

    system("cls");

    char h1='a',h2='b',v1='c',v2='d',b1='e',b2='f'; //this helps us in coloring player's move where 1 or 2 refers to playernumber
    char h = 205; //horizontal (odd,even)
    char v = 186; //vertical (even,odd)
    char b = 219; //box (even,even)

    int timediff = (t2-t1) / CLOCKS_PER_SEC;
    int Min,sec;

    sec = timediff % 60;
    Min = timediff / 60;

    for(int i=0; i<Size; i++)
    {
        printf("   \t\t\t\t\t");
        for(int j=0; j<Size; j++)
        {
            if(i==0 && j==0)
            {
                printf("  ",game[i][j]);
            }
            else if(i==0 || j==0)
            {
                printf(" %x",game[i][j]);

            }
            else if((i%2==1) && (j%2==0))
            {
                if(game[i][j]==h1)
                {
                    game[i][j]=h;
                    printf(BBLU"%c%c"reset,game[i][j],game[i][j]);
                    game[i][j]=h1;
                }
                else if(game[i][j]==h2)
                {
                    game[i][j]=h;
                    printf(BRED"%c%c"reset,game[i][j],game[i][j]);
                    game[i][j]=h2;
                }
                else
                {
                    printf("  ",game[i][j]);
                }


            }
            else if((i%2==0)&&(j%2==1))
            {
                if(game[i][j]==v1)
                {
                    game[i][j]=v;
                    printf(BBLU" %c"reset,game[i][j]);
                    game[i][j] =v1;
                }
                else if(game[i][j]==v2)
                {
                    game[i][j]=v;
                    printf(BRED" %c"reset,game[i][j]);
                    game[i][j]=v2;
                }
                else
                {
                    printf("  ",game[i][j]);
                }
            }
            else if((i%2==0)&&(j%2==0))
            {
                if(game[i][j]==b1)
                {
                    game[i][j]=b;
                    printf(BBLU"%c%c"reset,game[i][j],game[i][j]);
                    game[i][j]=b1;
                }
                else if(game[i][j]==b2)
                {
                    game[i][j]=b;
                    printf(BRED"%c%c"reset,game[i][j],game[i][j]);
                    game[i][j]=b2;
                }
                else
                {
                    printf("  ",game[i][j]);
                }
            }
            else if((i%2==1)&&(j%2==1))
            {
                game[i][j]=254;
                printf(" %c",game[i][j]);

            }
        }
        printf("\n");
    }
    printf("\n\n");
    printf(BBLU"        Player 1 name: %s\t\t\t\t\t\t"reset,name1);
    printf(BRED"        Player 2 name: %s\t\t\t\t"reset,name2);
    printf(BBLU"        Player 1 moves : %d\t\t\t\t\t\t"reset,moves1);
    printf(BRED"        Player 2 moves : %d\t\t\t\t"reset,moves2);
    printf(BBLU"        Score 1: %d\t\t\t\t\t\t"reset,score1);
    printf(BRED"                Score 2: %d\t\t\t\t\n\n"reset,score2);
    printf(BYEL"           Number of remaining moves : %d\t\t\t"reset,remMoves);
    printf(BYEL"          Time : %.2d:%.2d\n\n"reset,Min,sec);
    printf(BWHT" \t\tEnter number of row and column \t (for a choose 10)\t(for b choose 11)\n\t\t\t0, 0 for undo\t1, 1 for redo\t 2, 2 for save\t 3, 3 for main menu\n\n"reset);

    if(invalid==1)
    {
        printf(BYEL"    Invalid input, Try Again\n"reset);
    }
    if(undo==0){
        printf(BWHT"No moves to undo\n"reset);
    }

    if(remMoves!=0)
    {
        if(turn==1)
        {
            printf(BBLU"    Player's 1 turn: "reset);
        }
        else if(turn==2)
        {
            printf(BRED"    Player's 2 turn: "reset);
        }
    }
}
