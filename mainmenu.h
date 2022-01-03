void startGame(){
    int i;
    int j;

    printf(UWHT"\n Choose level of difficulty:\n\n"reset);
    printf(BWHT"  1-Easy         (enter 1 to choose)\n");
    printf(BWHT"  2-Difficult    (enter 2 to choose)\n\n ");
    printf(BWHT" Choose Number:");
    scanf("%d",&i);

    system("cls");

    printf(UWHT"\n Choose Game Mode\n\n"reset);
    printf(BWHT"  1- 2 players              (enter 1 to choose)\n");
    printf(BWHT"  2- 1 player VS Computer   (enter 2 to choose)\n\n");
    printf(BWHT" Choose Number:");
    scanf("%d",&j);



}

void checkNumMenu(int i){
    if(i==1){
        system("cls");
        startGame();

    }
    else if(i==2){
        system("cls");
        int k;
        printf(UWHT"\n Choose the saved game:\n\n"reset);
        printf(BWHT"1- File 1   (enter 1 to choose)\n");
        printf(BWHT"2- File 2   (enter 2 to choose)\n");
        printf(BWHT"3- File 3   (enter 3 to choose)\n\n");
        printf(BWHT" Choose Number:");
        scanf("%d",&k);


    }
    else if(i==3){
        system("cls");
        printf(UWHT"\t\t\t\tLeaderboard\n\n");
        printf(URED" Top 10 Players:\n\n"reset);
        printf(URED"\t\tPlayer Name \t\t\t Score"reset);

    }
    else if(i==4){
            system("cls");
            printf("Game Closed");
            exit(0);

    }
}


void menuDisplay(){

    int i;
    printf(UWHT"\t\t\t\tDots and Boxes\n\n"reset);
    printf(BWHT"\t\t\tWelcome to the game,Have Fun\n\n\n");
    printf(BWHT"1-Start Game:     (enter 1 to choose)\n");
    printf(BWHT"2-Load Game:      (enter 2 to choose)\n");
    printf(BWHT"3-Leaderboard:    (enter 3 to choose)\n");
    printf(BWHT"4-Exit:           (enter 4 to choose)\n\n");

    printf(BWHT" Choose a number to move on:");
    scanf("%d",&i);

    checkNumMenu(i);

//the user dont have to close the game and open it he can renter  if he enters wrong number and the below code does this
    while(i!=1 && i!=2 && i!=3 && i!=4){
        printf(BWHT"Invalid Number, Choose again:");
        scanf("%d",&i);
        checkNumMenu(i);
    }

}
