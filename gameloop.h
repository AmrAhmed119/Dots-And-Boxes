int gameloop(int n,int m,int turn,int Size,char game[Size][Size],char name1[],int namelen1,char name2[],int namelen2,int score1,int score2,int moves1,int moves2,int remMoves,int copygame[remMoves][7],int redogame[remMoves][8],int moves,int redomoves)
{

    int row,col;
    int u=1;
    int RowCol[2];
    char h = 205; //horizontal (odd,even)
    char v = 186; //vertical (even,odd)
    char b = 219; //box (even,even)
    int playing =1; //0 when the game finished
    int invalid=0;
    int r=0;
    int x=1;
    char h1='a',h2='b',v1='c',v2='d',b1='e',b2='f'; //this helps us in coloring player's move

    clock_t time_start;
    clock_t time_end ;
    time_start = clock();
    time_end = clock();


    printGame(invalid,Size,game,name1,name2,score1,score2,moves1,moves2,remMoves,turn,time_start,time_end,u,x);

    while(playing)   //Game Loop
    {
        u=1;
        x=1;

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
                undo(&remMoves,copygame,Size,game,&moves,&turn,&moves1,&moves2,&score1,&score2,m,redogame,&redomoves,r);
            }
        }

        else if((row==1) && (col==1))   //redo
        {
            if(redomoves==0){
                x=0;
            }
            else{

            redo(&remMoves,Size,game,&turn,&moves,&moves1,&moves2,&score1,&score2,m,redogame,copygame,&redomoves,r);
            }
        }

        else if((row==2) && (col==2))    //save
        {
            int fileNum;
            system("cls");
            printf(BYEL"\n\n   Enter File Number  (choose 1 , 2 or 3): "reset);
            scanf("%d",&fileNum);

            if((fileNum==1) || (fileNum==2) || (fileNum==3)){

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
            fwrite(copygame,sizeof(int),remMoves*7,save);
            fwrite(redogame,sizeof(int),remMoves*8,save);
            fwrite(&redomoves,sizeof(int),1,save);
            fwrite(&moves,sizeof(int),1,save);
            fwrite(game, sizeof(char),Size * Size,save);
            fwrite(&namelen1,sizeof(int),1,save);
            fwrite(name1,sizeof(char),namelen1,save);
                if(m==2){
                    fwrite(&namelen2,sizeof(int),1,save);
                    fwrite(name2,sizeof(char),namelen2,save);

                }

            fclose(save);
            //printGame(invalid,Size,game,name1,name2,score1,score2,moves1,moves2,remMoves,turn,time_start,time_end,u);
            }
            else{
                invalid=1;
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
        printGame(invalid,Size,game,name1,name2,score1,score2,moves1,moves2,remMoves,turn,time_start,time_end,u,x);


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
                //printf(BBLU"\n        Player 1 Wins ....Congratulations\n\t\t\t\t\n\t\t\tGame Ended,hope you enjoyed"reset);
                return 1;
            }
            else if(score2>score1)
            {
                //printf(BRED"\n        Player 2 Wins ....Congratulations\n\t\t\t\t\n\t\t\tGame Ended,hope you enjoyed"reset);
                return 2;
            }
            else
            {
               // printf(BYEL"\n        Tie game\n\t\t\t\tGame Ended,hope you enjoyed"reset);
               return 3;
            }
        }
    }
}


