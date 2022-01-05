void gameloop(int Size,char game[Size][Size],char name1[],char name2[],int score1,int score2,int moves1,int moves2,int remMoves){

    int row,col;
    int h = 205; //horizontal (odd,even)
    int v = 186; //vertical (even,odd)
    int b = 219; //box (even,even)
    int turn=1; //which player

    while(remMoves>-1){  //Game Loop


        printGame(Size,game,name1,name2,score1,score2,moves1,moves2,remMoves);

        printf(BWHT"\tEnter Row: ");
        scanf("%d",&row);

        printf(BWHT"\t\t\tEnter Column: ");
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

            /*if((game[row-1][col]=b) || (game[row+1][col]=b)){
                if(turn==1){
                    score1++;
                    turn=2;
                }
                else if(turn==2){
                    score2++;
                    turn=1;
                }
            }

            if(turn==1){
                turn=2;
            }
            else if(turn==2){
                turn=1;
            }*/

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

            /*if((game[row][col-1]=b) || (game[row][col+1]=b)){
                if(turn==1){
                    score1++;
                    turn=2;
                }
                else if(turn==2){
                    score2++;
                    turn=1;
                }
            }

            if(turn==1){
                turn=2;
            }
            else if(turn==2){
                turn=1;
            }*/
        }



      else{//invalid input


        }




    }






}
