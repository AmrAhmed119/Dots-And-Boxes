void gameloop(int n,int m,int Size,char game[Size][Size],char name1[],char name2[],int score1,int score2,int moves1,int moves2,int remMoves,int copygame[remMoves][7],int moves)
{

    int row,col;
    int u=1;
    int RowCol[2];
    char h = 205; //horizontal (odd,even)
    char v = 186; //vertical (even,odd)
    char b = 219; //box (even,even)
    int turn=1; //which player
    int playing =1; //0 when the game finished
    int invalid=0;
    char h1='a',h2='b',v1='c',v2='d',b1='e',b2='f'; //this helps us in coloring player's move

    clock_t time_start;
    clock_t time_end ;

    time_end = clock();

    time_start = clock();
    printGame(invalid,Size,game,name1,name2,score1,score2,moves1,moves2,remMoves,turn,time_start,time_end,u);

    while(playing)   //Game Loop
    {
        u=1;


        if( ((m==2) && (turn==1)) || ((m==2) && (turn==2)) || ((m==1) && (turn==1)))
        {

            printf(BWHT"\tEnter Row: ");
            scanf("%d",&row);

            printf(BWHT"\t\t\tEnter Column: ");
            scanf("%d",&col);
        }


        if((m==1) && (turn==2))
        {
            computer(n,Size,game,RowCol);
            row = RowCol[0];
            col = RowCol[1];
        }

        if((row==0) && (col==0))    //undo
        {
            if(moves==0){
                u=0;
            }
            else{
                undo(&remMoves,copygame,Size,game,&moves,&turn,&moves1,&moves2,&score1,&score2,m);
            }
        }

        else if((row==1) && (col==1))   //redo
        {

        }

        else if((row==2) && (col==2))    //save
        {


        }
        else if((row==3) && (col==3)) //mainmenu
        {
            system("cls");
            return;                       //this may cause stackover flow after alot of iterations.
        }

        else if((row%2==1) && (col%2==0))   //horizontal line
        {

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
                invalid=1;//invalid input
            }
            if(invalid!=1)
            {
                if((row-2)>0)
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
                if((row+2)<Size)
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

                if (((cmpch(game[row-1][col],b1)==0) || (cmpch(game[row-1][col],b2)==0))  && ((cmpch(game[row+1][col],b1)==0) || (cmpch(game[row+1][col],b2)==0)))
                {
                    if(turn==1)
                    {
                        copygame[moves][2]=turn;
                        score1=score1+2;
                        turn=2;
                    }
                    else if(turn==2)
                    {
                        copygame[moves][2]=turn;
                        score2=score2+2;
                        turn=1;
                    }
                }
                else if(((cmpch(game[row-1][col],b1)==0)  || (cmpch(game[row-1][col],b2)==0))  || ((cmpch(game[row+1][col],b1)==0) || (cmpch(game[row+1][col],b2)==0)))
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
                else{
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

                if((col-2)>0)
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

                if((col+2)<Size)
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
                if(((cmpch(game[row][col-1],b1)==0) || (cmpch(game[row][col-1],b2)==0))   && ((cmpch(game[row][col+1],b1)==0) || (cmpch(game[row][col+1],b2)==0)))
                {
                    if(turn==1)
                    {
                        copygame[moves][2]=turn;
                        score1=score1+2;
                        turn=2;
                    }
                    else if(turn==2)
                    {
                        copygame[moves][2]=turn;
                        score2=score2+2;
                        turn=1;
                    }
                }
                else if(((cmpch(game[row][col-1],b1)==0) || (cmpch(game[row][col-1],b2)==0)) || ((cmpch(game[row][col+1],b1)==0) || (cmpch(game[row][col+1],b2)==0)))
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
                else{
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
        printGame(invalid,Size,game,name1,name2,score1,score2,moves1,moves2,remMoves,turn,time_start,time_end,u);


        if(remMoves!=0)
        {
            playing=1;
        }
        else
        {
            playing=0;
        }

        if(playing==0)
        {
            if(score1>score2)
            {
                printf(BBLU"\n        Player 1 Wins ....Congratulations\n\t\t\t\t\n\t\t\tGame Ended,hope you enjoyed"reset);
            }
            else if(score2>score1)
            {
                printf(BRED"\n        Player 2 Wins ....Congratulations\n\t\t\t\t\n\t\t\tGame Ended,hope you enjoyed"reset);
            }
            else
            {
                printf(BYEL"\n        Tie game\n\t\t\t\tGame Ended,hope you enjoyed"reset);
            }
        }
    }
}


