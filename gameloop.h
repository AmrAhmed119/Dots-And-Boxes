int gameloop(int n,int m,int turn,int Size,char game[Size][Size],char name1[],int namelen1,char name2[],int namelen2,int score1,int score2,int moves1,int moves2,int remMoves,int scorearray[])
{

    int row,col;
    int RowCol[2]; //store row , col computer played
    char h = 205; //horizontal (odd,even)
    char v = 186; //vertical (even,odd)
    char b = 219; //box (even,even)
    int playing =1; //0 when the game finished
    int invalid=0,u=1,x=1; //variables (help us if there undo or redo moves can be played or not) and (invalid for invalid inputs)
    int moves=0,redomoves=0;
    int copygame[remMoves][7];   //for Undo
    int redogame[remMoves][8];   //for Redo
    int r=0;

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

    char h1='a',h2='b',v1='c',v2='d',b1='e',b2='f'; //variables help us in coloring player(1 or 2) move

    //for printing time
    clock_t time_start;
    clock_t time_end ;
    time_start = clock();
    time_end = clock();


    printGame(invalid,Size,game,name1,name2,score1,score2,moves1,moves2,remMoves,turn,time_start,time_end,u,x);

    while(playing)   //Game Loop
    {
        invalid=0;
        u=1;
        x=1;

        if(((m==2) && (turn==1)) || ((m==2) && (turn==2)) || ((m==1) && (turn==1)))  //player turn
        {

            printf(BWHT"\tEnter Row: ");
            row=checkint();
            printf(BWHT"\t\t\tEnter Column: ");
            col=checkint();
        }

        if((m==1) && (turn==2))  //computer turn
        {
            computer(n,Size,game,RowCol);
            row = RowCol[0];
            col = RowCol[1];
        }

        if((row==0) && (col==0))    //undo
        {
            if(moves==0)
            {
                u=0;
            }
            else
            {
                undo(&remMoves,copygame,Size,game,&moves,&turn,&moves1,&moves2,&score1,&score2,m,redogame,&redomoves,r);
            }
        }

        else if((row==1) && (col==1))   //redo
        {
            if(redomoves==0)
            {
                x=0;
            }
            else
            {
                redo(&remMoves,Size,game,&turn,&moves,&moves1,&moves2,&score1,&score2,m,redogame,copygame,&redomoves,r);
            }
        }

        else if((row==2) && (col==2))    //save
        {
            int fileNum;
            system("cls");
            printf(BYEL"\n\n   Enter File Number  (choose 1 , 2 or 3): "reset);
            fileNum = checkint();

            if((fileNum==1) || (fileNum==2) || (fileNum==3))
            {

                char whichfile[6];
                sprintf(whichfile,"File%d.bin",fileNum); // sprintf used to store output on char buffer which are specified in sprintf

                FILE *save;
                save = fopen(whichfile,"wb");  //saving game data in a file

                fwrite(&n,sizeof(int),1,save);
                fwrite(&m,sizeof(int),1,save);
                fwrite(&remMoves,sizeof(int),1,save);
                fwrite(&moves1,sizeof(int),1,save);
                fwrite(&moves2,sizeof(int),1,save);
                fwrite(&score1,sizeof(int),1,save);
                fwrite(&score2,sizeof(int),1,save);
                fwrite(&turn,sizeof(int),1,save);
                fwrite(game,sizeof(char),Size * Size,save);
                fwrite(&namelen1,sizeof(int),1,save);
                fwrite(name1,sizeof(char),namelen1,save);
                if(m==2)                //we dont have to save for computer
                {
                    fwrite(&namelen2,sizeof(int),1,save);
                    fwrite(name2,sizeof(char),namelen2,save);
                }
                fclose(save);

                printf(BYEL"\n   Game saved to %s\n  "reset,whichfile);
                system("pause");
            }
            else
            {
                printf(BYEL"\n  There is no existing file\n"reset);
                system("pause");
            }
        }

        else if((row==3) && (col==3)) //mainmenu
        {
            system("cls");
            return;
        }

        else if((row%2==1) && (col%2==0))   //horizontal line
        {


            redomoves=0;
            for(int i=0; i<remMoves; i++)
            {
                for(int j=0; j < 8; j++)
                {
                    redogame[i][j]=0;
                }
            }

            if(game[row][col] == ' ')
            {
                invalid=0;

                if(turn==1)
                {
                    game[row][col] = h1;
                }
                else
                {
                    game[row][col] = h2;
                }
                remMoves--;
                if(turn==1)
                {
                    moves1++;
                }
                else
                {
                    moves2++;
                }
                copygame[moves][0]=row;
                copygame[moves][1]=col;
            }
            else
            {
                invalid=1;
            }
            if(invalid!=1)
            {
                if((row-2)>0)          //CheckBox
                {
                    if( (cmpch(game[row-2][col],h1)==0) || (cmpch(game[row-2][col],h2)==0) )
                    {
                        if( (cmpch(game[row-1][col-1],v1)==0) || (cmpch(game[row-1][col-1],v2)==0))
                        {
                            if( (cmpch(game[row-1][col+1],v1)==0) || (cmpch(game[row-1][col+1],v2)==0))
                            {
                                if(turn==1)
                                {
                                    game[row-1][col]=b1;
                                    copygame[moves][3]=row-1;
                                    copygame[moves][4]=col;
                                }
                                else
                                {
                                    game[row-1][col]=b2;
                                    copygame[moves][3]=row-1;
                                    copygame[moves][4]=col;
                                }
                            }
                        }
                    }
                }
                if((row+2)<Size)    //CheckBox
                {
                    if( (cmpch(game[row+2][col],h1)==0) || (cmpch(game[row+2][col],h2)==0))
                    {
                        if ((cmpch(game[row+1][col-1],v1)==0) || (cmpch(game[row+1][col-1],v2)==0))
                        {
                            if( (cmpch(game[row+1][col+1],v1)==0) || (cmpch(game[row+1][col+1],v2)==0) )
                            {
                                if(turn==1)
                                {
                                    game[row+1][col]=b1;
                                    copygame[moves][5]=row+1;
                                    copygame[moves][6]=col;
                                }
                                else
                                {
                                    game[row+1][col]=b2;
                                    copygame[moves][5]=row+1;
                                    copygame[moves][6]=col;
                                }
                            }
                        }
                    }
                }

                if (((cmpch(game[row-1][col],b1)==0) || (cmpch(game[row-1][col],b2)==0))  && ((cmpch(game[row+1][col],b1)==0) || (cmpch(game[row+1][col],b2)==0)))  //check two boxes
                {
                    if(turn==1)
                    {
                        copygame[moves][2]=turn;
                        score1+=2;
                        turn=2;
                    }
                    else if(turn==2)
                    {
                        copygame[moves][2]=turn;
                        score2+=2;
                        turn=1;
                    }
                }
                else if(((cmpch(game[row-1][col],b1)==0)  || (cmpch(game[row-1][col],b2)==0))  || ((cmpch(game[row+1][col],b1)==0) || (cmpch(game[row+1][col],b2)==0)))  //check one box
                {
                    if(turn==1)
                    {
                        copygame[moves][2]=turn;
                        score1++;
                        turn=2;
                    }
                    else if(turn==2)
                    {
                        copygame[moves][2]=turn;
                        score2++;
                        turn=1;
                    }
                }
                else
                {
                    copygame[moves][2]=turn;
                }


                if(turn==1)
                {
                    turn=2;
                }
                else if(turn==2)
                {
                    turn=1;
                }
                moves++;
            }

        }
        else if((row%2==0) && (col%2==1))    //vertical line
        {

            redomoves=0;
            for(int i=0; i<remMoves; i++)
            {
                for(int j=0; j < 8; j++)
                {
                    redogame[i][j]=0;
                }
            }


            if(game[row][col] == ' ')
            {
                invalid=0;

                if(turn==1)
                {
                    game[row][col] = v1;
                }
                else
                {
                    game[row][col] = v2;
                }
                remMoves--;
                if(turn==1)
                {
                    moves1++;
                }
                else
                {
                    moves2++;
                }
                copygame[moves][0]=row;
                copygame[moves][1]=col;
            }
            else
            {
                invalid=1;

            }

            if(invalid!=1)
            {

                if((col-2)>0)       //CheckBox
                {
                    if((cmpch(game[row][col-2],v1)==0) || (cmpch(game[row][col-2],v2)==0))
                    {
                        if((cmpch(game[row-1][col-1],h1)==0) || (cmpch(game[row-1][col-1],h2)==0))
                        {
                            if((cmpch(game[row+1][col-1],h1)==0) || (cmpch(game[row+1][col-1],h2)==0))
                            {
                                if(turn==1)
                                {
                                    game[row][col-1]=b1;
                                    copygame[moves][3]=row;
                                    copygame[moves][4]=col-1;

                                }
                                else
                                {
                                    game[row][col-1]=b2;
                                    copygame[moves][3]=row;
                                    copygame[moves][4]=col-1;
                                }

                            }
                        }
                    }
                }

                if((col+2)<Size)        //CheckBox
                {
                    if((cmpch(game[row][col+2],v1)==0) || (cmpch(game[row][col+2],v2)==0))
                    {
                        if((cmpch(game[row-1][col+1],h1)==0) || (cmpch(game[row-1][col+1],h2)==0))
                        {
                            if((cmpch(game[row+1][col+1],h1)==0) || (cmpch(game[row+1][col+1],h2)==0))
                            {
                                if(turn==1)
                                {
                                    game[row][col+1]=b1;
                                    copygame[moves][5]=row;
                                    copygame[moves][6]=col+1;
                                }
                                else
                                {
                                    game[row][col+1]=b2;
                                    copygame[moves][5]=row;
                                    copygame[moves][6]=col+1;
                                }
                            }
                        }
                    }
                }
                if(((cmpch(game[row][col-1],b1)==0) || (cmpch(game[row][col-1],b2)==0))   && ((cmpch(game[row][col+1],b1)==0) || (cmpch(game[row][col+1],b2)==0)))  //get two boxes
                {
                    if(turn==1)
                    {
                        copygame[moves][2]=turn;
                        score1+=2;
                        turn=2;
                    }
                    else if(turn==2)
                    {
                        copygame[moves][2]=turn;
                        score2+=2;
                        turn=1;
                    }
                }
                else if(((cmpch(game[row][col-1],b1)==0) || (cmpch(game[row][col-1],b2)==0)) || ((cmpch(game[row][col+1],b1)==0) || (cmpch(game[row][col+1],b2)==0)))  //get one box
                {
                    if(turn==1)
                    {
                        copygame[moves][2]=turn;
                        score1++;
                        turn=2;
                    }
                    else if(turn==2)
                    {
                        copygame[moves][2]=turn;
                        score2++;
                        turn=1;
                    }
                }
                else
                {
                    copygame[moves][2]=turn;
                }


                if(turn==1)
                {
                    turn=2;
                }
                else if(turn==2)
                {
                    turn=1;
                }
                moves++;
            }
        }

        else //invalid input
        {
            invalid=1;

        }


        time_end = clock();
        printGame(invalid,Size,game,name1,name2,score1,score2,moves1,moves2,remMoves,turn,time_start,time_end,u,x);

        //print grid in text file for debugging

        FILE *debug;
        debug = fopen("Debug.txt","w");
        if(debug==NULL)
        {
            printf("Error");
        }
        else
        {
            for(int i=0; i<Size; i++)
            {
                fprintf(debug,"   \t\t\t\t\t");
                for(int j=0; j<Size; j++)
                {
                    if(i==0 && j==0)
                    {
                        fprintf(debug,"  ",game[i][j]);
                    }
                    else if(i==0 || j==0)
                    {
                        fprintf(debug," %x",game[i][j]);

                    }
                    else if((i%2==1) && (j%2==0))
                    {
                        if(game[i][j]==h1)
                        {
                            game[i][j]=h;
                            fprintf(debug,"%c%c",'=','=');
                            game[i][j]=h1;
                        }
                        else if(game[i][j]==h2)
                        {
                            game[i][j]=h;
                            fprintf(debug,"%c%c",'=','=');
                            game[i][j]=h2;
                        }
                        else
                        {
                            fprintf(debug,"  ",game[i][j]);
                        }


                    }
                    else if((i%2==0)&&(j%2==1))
                    {
                        if(game[i][j]==v1)
                        {
                            game[i][j]=v;
                            fprintf(debug," %c",'|');
                            game[i][j] =v1;
                        }
                        else if(game[i][j]==v2)
                        {
                            game[i][j]=v;
                            fprintf(debug," %c",'|');
                            game[i][j]=v2;
                        }
                        else
                        {
                            fprintf(debug,"  ",game[i][j]);
                        }
                    }
                    else if((i%2==0)&&(j%2==0))
                    {
                        if(game[i][j]==b1)
                        {
                            game[i][j]=b;
                            fprintf(debug,"%c%c",game[i][j],game[i][j]);
                            game[i][j]=b1;
                        }
                        else if(game[i][j]==b2)
                        {
                            game[i][j]=b;
                            fprintf(debug,"%c%c",game[i][j],game[i][j]);
                            game[i][j]=b2;
                        }
                        else
                        {
                            fprintf(debug,"  ",game[i][j]);
                        }
                    }
                    else if((i%2==1)&&(j%2==1))
                    {
                        game[i][j]=254;
                        fprintf(debug," %c",game[i][j]);

                    }
                }
                fprintf(debug,"\n");
            }

            fprintf(debug,"\n\n");
            fprintf(debug,"        Player 1 name: %s\t\t\t\t\t\t",name1);
            fprintf(debug,"        Player 2 name: %s\t\t\t\t\n",name2);
            fprintf(debug,"        Player 1 moves : %d\t\t\t\t\t\t",moves1);
            fprintf(debug,"        Player 2 moves : %d\t\t\t\t\n",moves2);
            fprintf(debug,"        Score 1: %d\t\t\t\t\t\t",score1);
            fprintf(debug,"                Score 2: %d\t\t\t\t\n\n",score2);
            fprintf(debug,"           Number of remaining moves : %d\t\t\t",remMoves);

            int timediff = (time_end-time_start) / CLOCKS_PER_SEC;
            int Min,sec;

            sec = timediff % 60;
            Min = timediff / 60;
            fprintf(debug,"          Time : %.2d:%.2d\n\n",Min,sec);

            if(remMoves!=0)
            {
            if(turn==1)
            {
                fprintf(debug,"    Player's 1 turn: ");
            }
            else if(turn==2)
            {
                fprintf(debug,"    Player's 2 turn: ");
            }
            }
        }
        fclose(debug);

        if(remMoves!=0)
        {
            playing=1;  //still game on
        }
        else
        {
            playing=0;  //game ends
        }

        if(playing==0)  //End game
        {
            scorearray[0] = score1;
            scorearray[1] = score2;
            if(score1>score2)
            {
                return 1;    //Player 1 wins
            }
            else if(score2>score1)
            {
                return 2;   //Player 2 wins
            }
            else
            {
                return 3;   //Tie game
            }
        }
    }
}


