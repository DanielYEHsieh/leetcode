char* longestPalindrome(char* s) {
    int n = strlen(s);
    int Extend = 0;
    int i = 0;
    bool fgContinueO = 1;
    bool fgContinueE = 1;
    int *PSL = NULL;
    int *PSL_O = NULL;
    int *PSL_E = NULL;
    int *EvenString = NULL;
    PSL = malloc(n * sizeof(int));
    PSL_O = malloc(n * sizeof(int));
    PSL_E = malloc(n * sizeof(int));
    memset(PSL, 0, n * sizeof(int));
    memset(PSL_O, 0, n * sizeof(int));
    memset(PSL_E, 0, n * sizeof(int));
    EvenString = malloc(n * sizeof(int));
    memset(EvenString, 0, n * sizeof(int));
    for ( i=0; i<n; i++)
    {            
        Extend = 0;
        //printf("%d:\n",i);
        fgContinueE = 1;
        fgContinueO = 1;
        while (i - Extend >= 0 && i + Extend < n)
        {

            //printf("%c %c i %d, e %d\n",s[i + Extend], s[i - Extend], i , Extend);
            //if (s[i + Extend] == s[i - Extend])
            if (s[i + 1 + Extend] == s[i - Extend] && s[i] == s[i+1] && fgContinueE)
            {
                PSL_E[i]++;
                
                //printf("even [%d]\n", i);
            }
            else
                fgContinueE = 0;
            //else if (s[i + 1 + Extend] == s[i - Extend] && s[i] == s[i+1])
            if (s[i + Extend] == s[i - Extend] && fgContinueO)
            {
                PSL_O[i]++;
                //printf("odd [%d]\n", i);
            }
            else
                fgContinueO = 0;
            
            if(!fgContinueO && !fgContinueE)
                break;
            Extend++;
        }
        //printf("\n");
        if (PSL_E[i] >= PSL_O[i])
        {
            EvenString[i] = 1;
            PSL[i] = PSL_E[i];
        }
        else
            PSL[i] = PSL_O[i];
    }
    int Index = 0;
    for ( i=0; i<n; i++)
    {
        //if (PSL[i] > 1)
            //printf("PSL[%d]%d , EvenString %d\n", i, PSL[i], EvenString[i]);
        if (PSL[Index] < PSL[i])
            Index = i;
        else if (PSL[Index] == PSL[i] && !EvenString[Index] && EvenString[i] )
            Index = i;
    }
    //if (PSL[Index] > 1 )
        PSL[Index]--;
    int j = 0;
    j = Index + PSL[Index] + 1;
    if(EvenString[Index])
        j++;
    s[j] = '\0';
    //printf("start %d, end %d, n %d\n", Index - PSL[Index], j, n);
    return &s[Index - PSL[Index]];
}

