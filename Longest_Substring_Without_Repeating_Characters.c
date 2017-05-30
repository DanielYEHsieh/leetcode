//16ms beats 92.5%
#define FALSE   0
#define TRUE    1

int lengthOfLongestSubstring(char* s) {
    int Ans[2] = {0,1};
    int CurrentLength[2] = {0,1};    
    
    int index = 1;
    char Current = *s;
    char Prev = *s;
    char* CheckString = s;    
    int asc[320][127] = {0};
    int ascIndex[127] = {0};    
    
    int i = 0;
    bool fgDebug = FALSE;
    
    if(*s == 'a' && *(s+1) == 'u')
        fgDebug = TRUE;
    
    if(*s == NULL)
        return 0;
    while (*CheckString){
        i = 0;
        if (asc[i][*CheckString] != 0){
            ascIndex[*CheckString]++;
            i = ascIndex[*CheckString];
        }
        
        asc[i][*CheckString] = index;
        
        if(i > 0){ // means repeater apears
            if( asc[i-1][*CheckString] < CurrentLength[0]) { // means that the previous repeater is not in the current length calculation
                CurrentLength[1] = index;
            }
            else {
                CurrentLength[0] = asc[i-1][*CheckString];
                
                //return CurrentLength[0];
            }
        }
        if(i == 0){
            CurrentLength[1] = index;
            //if(*CheckString == 'u')
                //return index+123;
        }
               
       if( (CurrentLength[1] - CurrentLength[0]) > (Ans[1] - Ans[0]) ){
           Ans[1] = CurrentLength[1];
           Ans[0] = CurrentLength[0];
       }        
        
        index++;
        CheckString++;
        
    }
    return Ans[1] - Ans[0];
}
