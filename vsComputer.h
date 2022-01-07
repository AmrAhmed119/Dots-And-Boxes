void computer(int n,int Size,char game[Size][Size],int RowCol[])
{

    char h2='b',v2='d'; //this helps us in coloring player's move
    int row,col;

    if(n==2)   //easy -> numbers from 1 to 5
    {

        int lower = 1;
        int upper = 5;

        row = (rand() % (upper-lower+1)) + lower;
        col = (rand() % (upper-lower+1)) + lower;

        while( ((row%2==0) && (col%2==0)) || ((row%2==1) && (col%2==1)) || (game[row][col]!=' ') )
        {

            row = (rand() % (upper-lower+1)) + lower;
            col = (rand() % (upper-lower+1)) + lower;
        }

        RowCol[0] = row;
        RowCol[1] = col;

    }
    else if(n==5)    //difficult -> numbers from 1 to 11
    {

        int lower = 1;
        int upper = 11;

        row = (rand() % (upper-lower+1)) + lower;
        col = (rand() % (upper-lower+1)) + lower;

        while( ((row%2==0) && (col%2==0)) || ((row%2==1) && (col%2==1)) || (game[row][col]!=' ') )
        {

            row = (rand() % (upper-lower+1)) + lower;
            col = (rand() % (upper-lower+1)) + lower;
        }

        RowCol[0] = row;
        RowCol[1] = col;
    }

}
