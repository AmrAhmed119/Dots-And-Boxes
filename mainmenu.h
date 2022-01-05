int startMenu(int i){
    printf(UWHT"\t\t\t\tDots and Boxes\n\n"reset);
    printf(UCYN"\t\t\tWelcome to the game,Have Fun\n\n\n"reset);
    printf(BCYN"  1-Start Game:     (enter 1 to choose)\n"reset);
    printf(BCYN"  2-Load Game:      (enter 2 to choose)\n"reset);
    printf(BCYN"  3-Leaderboard:    (enter 3 to choose)\n"reset);
    printf(BCYN"  4-Exit:           (enter 4 to choose)\n\n"reset);

    printf(BWHT" Choose a number to move on:"reset);
    scanf("%d",&i);

    while(i!=1 && i!=2 && i!=3 && i!=4){
        printf(BWHT"Invalid Number, Choose again:"reset);
        scanf("%d",&i);
        }

    return i;
}

int difficuilty(int j){
    system("cls");

    printf(UWHT"\n Choose level of difficulty:\n\n"reset);
    printf(BCYN"  1-Easy          (enter 1 to choose)\n"reset);
    printf(BCYN"  2-Difficult     (enter 2 to choose)\n\n "reset);

    printf(BWHT" Choose Number:");
    scanf("%d",&j);

    while(j!=1 && j!=2){
        printf(BWHT"Invalid Number, Choose again:"reset);
        scanf("%d",&j);
        }
    if(j==1){
        return 2;
    }
    else if(j==2){
        return 5;
    }
}

int mode(int z){
    system("cls");

    printf(UWHT"\n Choose Game Mode:\n\n"reset);
    printf(BCYN"  1- 1 player vs computer    (enter 1 to choose)\n");
    printf(BCYN"  2- 2 players               (enter 2 to choose)\n\n");
    printf(BWHT" Choose Number:");
    scanf("%d",&z);

    while(z!=1 && z!=2){
        printf(BWHT"Invalid Number, Choose again:"reset);
        scanf("%d",&z);
        }
    return z;
}







