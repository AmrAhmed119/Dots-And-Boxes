void gameloop(int Size,char game[Size][Size],char name1[],char name2[],int score1,int score2,int moves1,int moves2,int remMoves){

    int row,col;
    int h = 205; //horizontal (odd,even)
    int v = 186; //vertical (even,odd)
    int b = 219; //box (even,even)

    while(remMoves>-1){  //Game Loop


        printGame(Size, game, name1, name2, score1, score2, moves1, moves2,remMoves);

        printf(BWHT"  Enter Row: ");
        scanf("%d",&row);

        printf(BWHT"  Enter Column: ");
        scanf("%d",&col);

        if((row==0) && (col==0)){   //undo

        }

        else if((row==1) && (col==1)){  //redo

        }

        else if((row==2) && (col==2)){   //save


        }
        else if((row==3) && (col==3)){//mainmenu
            system("cls");
            main();                       //this may cause stackover flow after alot of iterations.
        }

        else if((row%2==1) && (col%2==0)){  //horizontal line

            if(game[row][col] == ' '){
                game[row][col] = h;
                remMoves--;
            }
            if((row-2)>0){
                if(cmpch(game[row-2][col],h)==0){
                   if(cmpch(game[row-1][col-1],v)==0){
                       if(cmpch(game[row-1][col+1],v)==0){
                            game[row-1][col]=b;
                       }
                   }
                }
            }
            if((row+2)<Size){
                if(cmpch(game[row+2][col],h)==0){
                        if(cmpch(game[row+1][col-1],v)==0){
                            if(cmpch(game[row+1][col+1],v)==0){
                                game[row+1][col]=b;
                            }
                        }
                }
            }
        }

        else if((row%2==0) && (col%2==1)){   //vertical line
            if(game[row][col] == ' '){
                game[row][col] = v;
                remMoves--;
            }
            if((col-2)>0){
                if(cmpch(game[row][col-2],v)==0){
                        if(cmpch(game[row-1][col-1],h)==0){
                            if(cmpch(game[row+1][col-1],h)==0){
                                game[row][col-1]=b;

                            }
                        }
                }
            }

            if((col+2)<Size){
                if(cmpch(game[row][col+2],v)==0){
                        if(cmpch(game[row-1][col+1],h)==0){
                            if(cmpch(game[row+1][col+1],h)==0){
                                game[row][col+1]=b;
                            }
                        }
                }
            }
        }


      else{//invalid input


        }























    }






}




