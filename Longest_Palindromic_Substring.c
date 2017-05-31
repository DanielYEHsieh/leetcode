//ongoing

#define MAX_INT 65535

char arHasTB[128][65535] = {'\n'};
int arHasTB_Index[128] = {0};
char* longestPalindrome(char* s) {
    char* CurChar = NULL;
	int Index = 0;
	int CharIndex = 0;
	CurChar = s;
	while (*CurChar != '\n' && *CurChar != EOF  && *CurChar !=' ' && *CurChar > 0 && *CurChar < 128) {
	    printf("%c", *CurChar);
		CharIndex = (int)(*CurChar);
		arHasTB[CharIndex][arHasTB_Index[CharIndex]] = Index;
		arHasTB_Index[CharIndex]++;
		Index++;
		CurChar++;
	}
	printf("\n");
	printf("Index %d\n",Index);

	return 0;
}
