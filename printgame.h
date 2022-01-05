void printGame(int Size,char game[Size][Size],char name1[],char name2[],int score1,int score2,int moves1,int moves2,int remMoves){

    system("cls");

    for(int i=0;i<Size;i++){
        printf("   \t\t\t\t\t");
        for(int j=0;j<Size;j++){
            if(i==0 && j==0){
                printf("  ",game[i][j]);
            }
            else if(i==0 || j==0){
                printf(" %x",game[i][j]);

            }
            /*else if((i%2==1) && (j%2==0)){
                printf("%c%c",game[i][j],game[i][j]);


            }*/
            else if(cmpch(game[i][j],219)==0){
                printf("%c%c",game[i][j],game[i][j]);
            }
            else {
                printf(" %c",game[i][j]);
            }

        }
        printf("\n");
}
printf("\n\n");
printf(BBLU"        Player 1 name: %s\t\t\t\t\t\t"reset,name1);
printf(BRED"        Player 2 name: %s\t\t\t\t"reset,name2);
printf(BBLU"        Number of moves 1: %d\t\t\t\t\t\t"reset,moves1);
printf(BRED"        Number of moves 2: %d\t\t\t\t"reset,moves2);
printf(BBLU"        Score 1:%d\t\t\t\t\t\t"reset,score1);
printf(BRED"                Score 2:%d\t\t\t\t\n\n"reset,score2);
printf(BYEL"           Number of remaining moves: %d\t\t\t"reset,remMoves);
printf(BYEL"          Time : \n\n"reset);

printf(BWHT"   Enter number of row and column \t(for a choose 10)\t (for b choose 11)\n         0, 0 for undo\t1, 1 for redo\t 2, 2 for save\t 3, 3 for main menu\n\n"reset);






























}
