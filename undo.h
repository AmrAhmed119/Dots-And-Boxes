void undo(int*remMoves,int copygame[*remMoves][7],int Size,char game[Size][Size],int*moves,int*turn,int*moves1,int*moves2,int*score1,int*score2,int m,int redogame[*remMoves][8],int*redomoves,int r)
{
    if(m==2)
    {
        game[copygame[*moves-1][0]][copygame[*moves-1][1]]=' ';
        redogame[*redomoves][0]=copygame[*moves-1][0];
        redogame[*redomoves][1]=copygame[*moves-1][1];
        redogame[*redomoves][2]=*turn;
        *remMoves=*remMoves+1;
        if(copygame[*moves-1][3] != 0)
        {
            game[copygame[*moves-1][3]][copygame[*moves-1][4]]=' ';
            redogame[*redomoves][3]=copygame[*moves-1][3];
            redogame[*redomoves][4]=copygame[*moves-1][4];
            if(*turn == 1)
            {
                *score1 -= 1;
            }
            else
            {
                *score2 -= 1;
            }
        }
        if(copygame[*moves-1][5] != 0)
        {
            game[copygame[*moves-1][5]][copygame[*moves-1][6]]=' ';
            redogame[*redomoves][5]=copygame[*moves-1][5];
            redogame[*redomoves][6]=copygame[*moves-1][6];
            if(*turn == 1)
            {
                *score1 -= 1;
            }
            else
            {
                *score2 -= 1;
            }
        }
        *turn=copygame[*moves-1][2];
        if(copygame[*moves-1][2]==1)
        {
            *moves1=*moves1-1;
        }
        else
        {
            *moves2=*moves2-1;
        }
        *moves-=1;
        *redomoves+=1;
    }
    else
    {
        while(1)
        {
            if(copygame[*moves-1][2]==1)
            {
                game[copygame[*moves-1][0]][copygame[*moves-1][1]]=' ';
                redogame[*redomoves][0]=copygame[*moves-1][0];
                redogame[*redomoves][1]=copygame[*moves-1][1];
                redogame[*redomoves][2]=1;
                r+=1;
                if(copygame[*moves-1][3] != 0)
                {
                    game[copygame[*moves-1][3]][copygame[*moves-1][4]]=' ';
                    redogame[*redomoves][3]=copygame[*moves-1][3];
                    redogame[*redomoves][4]=copygame[*moves-1][4];
                    *score1-=1;
                }
                if(copygame[*moves-1][5] != 0)
                {
                    game[copygame[*moves-1][5]][copygame[*moves-1][6]]=' ';
                    redogame[*redomoves][5]=copygame[*moves-1][5];
                    redogame[*redomoves][6]=copygame[*moves-1][6];
                    *score1-=1;
                }
                redogame[*redomoves][7]=r;
                r=0;
                *moves1-=1;
                *moves-=1;
                *remMoves+=1;
                *turn=1;
                *redomoves+=1;
                break;

            }
            else//removing computer moves
            {
                game[copygame[*moves-1][0]][copygame[*moves-1][1]]=' ';
                redogame[*redomoves][0]=copygame[*moves-1][0];
                redogame[*redomoves][1]=copygame[*moves-1][1];
                redogame[*redomoves][2]=2;
                r+=1;
                if(copygame[*moves-1][3] != 0)
                {
                    game[copygame[*moves-1][3]][copygame[*moves-1][4]]=' ';
                    redogame[*redomoves][3]=copygame[*moves-1][3];
                    redogame[*redomoves][4]=copygame[*moves-1][4];
                    *score2-=1;
                }
                if(copygame[*moves-1][5] != 0)
                {
                    game[copygame[*moves-1][5]][copygame[*moves-1][6]]=' ';
                    redogame[*redomoves][5]=copygame[*moves-1][5];
                    redogame[*redomoves][6]=copygame[*moves-1][6];
                    *score2-=1;
                }
                *moves2-=1;
                *moves-=1;
                *remMoves+=1;
                *redomoves+=1;
            }
        }
    }
}
