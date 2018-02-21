#define MAX_INT 2147483647
#define LESS_INT -2147483648
int reverse(int x) {
    int Ans = 0;
    if ( x >= 0){
        while (x > 0)
        {
            if ((Ans ==( MAX_INT / 10) && ( (x % 10) > 7 )) || Ans > ( MAX_INT / 10) )
                return 0;
            else
                Ans = (x % 10) + Ans * 10;
            x = x / 10;
        }
    }
    else{
        x = x * (-1);
        while (x > 0)
        {
            if ((Ans ==( MAX_INT / 10) && ( (x % 10) > 7 )) || Ans > ( MAX_INT / 10) )
                return 0;
            else
                Ans = (x % 10) + Ans * 10;
            x = x / 10;
        }
        Ans = Ans * (-1);
    }

    return Ans;
}
