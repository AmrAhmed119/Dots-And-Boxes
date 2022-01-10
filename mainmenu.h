int startMenu()
{
    int i;
    printf(UWHT"\t\t\t\tDots and Boxes\n\n"reset);
    printf(UCYN"\t\t\tWelcome to the game,Have Fun\n\n\n"reset);
    printf(BCYN"  1-Start Game:     (enter 1 to choose)\n"reset);
    printf(BCYN"  2-Load Game:      (enter 2 to choose)\n"reset);
    printf(BCYN"  3-Leaderboard:    (enter 3 to choose)\n"reset);
    printf(BCYN"  4-Exit:           (enter 4 to choose)\n\n"reset);
    printf(BWHT" Choose a number to move on:"reset);
    i = checkint();

    while(i!=1 && i!=2 && i!=3 && i!=4)        //for wrong answer
    {
        printf(BWHT"Invalid Number, Choose again:"reset);
        i = checkint();
    }

    return i;
}

int difficuilty(int j)
{
    system("cls");

    printf(UWHT"\n Choose level of difficulty:\n\n"reset);
    printf(BCYN"  1-Easy          (enter 1 to choose)\n"reset);
    printf(BCYN"  2-Medium        (enter 2 to choose)\n"reset);
    printf(BCYN"  3-Hard          (enter 3 to choose)\n"reset);
    printf(BCYN"  4-Difficult     (enter 4 to choose)\n\n "reset);

    printf(BWHT" Choose Number:");
    j = checkint();

    while((j!=1) && (j!=2) && (j!=3) && (j!=4))   //for wrong answer
    {
        printf(BWHT"Invalid Number, Choose again:"reset);
        j = checkint();
    }
    if(j==1)
    {
        return 2;
    }
    if(j==2)
    {
        return 3;
    }
    else if(j==3)
    {
        return 4;
    }
    else if(j==4)
    {
        return 5;
    }
    return;
}

int mode(int z)
{
    system("cls");

    printf(UWHT"\n Choose Game Mode:\n\n"reset);
    printf(BCYN"  1- 1 player vs computer    (enter 1 to choose)\n");
    printf(BCYN"  2- 2 players               (enter 2 to choose)\n\n");
    printf(BWHT" Choose Number:");
    z = checkint();

    while(z!=1 && z!=2)           //for wrong answer
    {
        printf(BWHT"Invalid Number, Choose again:"reset);
        z = checkint();
    }
    return z;
}
