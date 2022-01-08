int checkint() //avoiding error of not entering a number
{
    int res,x;
    res=scanf("%d",&x);
    if(res==1)
    {
        if(x<0)
        {
            return -1;
        }
        else
        {
            return x;
        }
    }
    else
    {
        clearerr(stdin);
        scanf("%*s");
        return -1;
    }
}

