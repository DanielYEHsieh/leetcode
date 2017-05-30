
// 8ms beats 100%
#define TRUE 1
#define FALSE 0

#define NonNegMax 2147483647
#define NegMax  -2147483648
int myAtoi(char* str) {
    int AtoIanswer = 0;
    bool fgDebug = FALSE;
    bool fgNeg = FALSE;
    if(strlen(str) ==0 )
        return 0;
    if(strlen(str) ==1 ){
        if(*str == '+' || *str == '-'){
            return 0;
        }
        else {
            return *str - '0';
        }
    }
 
    while(*str == ' '){
        str++;
    }
    
    
    
    if(*str == '-'){
        fgNeg = TRUE;
        str++;
        while(strlen(str) !=0 ){
            if(*str == '+' || *str == '-'  || *str < '0' || *str > '9'){
                if(AtoIanswer)
                    return -AtoIanswer;
                else
                    return 0;
            }
            else if (*str == ' ')
             return 0;
            else {
                if(AtoIanswer * 10 + *str - '0' < AtoIanswer || AtoIanswer > NonNegMax/10)
                    return NegMax;
                else
                    AtoIanswer = AtoIanswer * 10 + *str - '0' ;
            }
            str++;
        }
    }
    else if (*str == '+'){
        str++;
        while(strlen(str) !=0 ){
            if(*str == '+' || *str == '-' || *str < '0' || *str > '9'){
                if(AtoIanswer)
                    return AtoIanswer;
                else
                    return 0;
            }
            else if (*str == ' ')
             return 0;
            else {
                if(AtoIanswer * 10 + *str - '0' < AtoIanswer || AtoIanswer > NonNegMax/10)
                    return NonNegMax;
                else
                    AtoIanswer = AtoIanswer * 10 + *str - '0' ;
            }
            str++;
        }       
    }
    else {
        while(strlen(str) !=0 ){
            if(*str == '+' || *str == '-' || *str < '0' || *str > '9'){
                if(AtoIanswer )
                    return AtoIanswer;
                else
                    return 0;
            }
            else if (*str == ' '){
             str++;
            }
            else {
                if(AtoIanswer * 10 + *str - '0' < AtoIanswer || AtoIanswer > NonNegMax/10)
                    return NonNegMax;
                else
                    AtoIanswer = AtoIanswer * 10 + *str - '0' ;
            }
            str++;
        }

    }
        if(fgNeg)
            return -AtoIanswer;
        else
            return AtoIanswer;
}
