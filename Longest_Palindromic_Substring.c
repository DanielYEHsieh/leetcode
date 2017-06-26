//ongoing, 90/94 passed 

char* longestPalindrome(char* s) {
    char* CurChar = NULL;
	long int Index = 0;
	long int RefIndex = 0;
	long int TmpRefIndex = 0;
	long int AnsIndex = 0;
	long int Anslength = 0;
	long int CurrentLength = 0;
	long int TmpCurrentLength = 0;
	bool fgPalindromeStarts = 0;
	bool fgSubPalindromeStarts = 0;
	bool fgSkip = 0;
	bool fgAns1CharRepeat = 0;
	bool fgAns12CharRepeat = 0;
	long int temp = 0;
	char* AnsChar = NULL;
	CurChar = s;
	
	while (*CurChar != '\n' && *CurChar != EOF  && *CurChar !=' ' && *CurChar > 0 && *CurChar < 128) {
	    //printf("%c,AI %d RI %d PI %d, P%d AL %d CL %d I %d R%d\n",*CurChar,AnsIndex, RefIndex, TmpRefIndex, fgPalindromeStarts, Anslength,CurrentLength,Index, fgAns1CharRepeat );
	    fgSkip = 0;
        if (Index == 1) {
	        if (*CurChar ==  *(CurChar - 1)) {
	            Anslength = 2;
	            CurrentLength = 2;
	            fgAns1CharRepeat = 1;
	            AnsIndex = 0;
	            RefIndex = 0;
	            fgPalindromeStarts = 1;
	            fgSkip = 1;
	            //printf("hit3 \n");
	        }
	    }
	    else if (Index == 2) {
	        if (*CurChar ==  *(CurChar - 2)) {
	            RefIndex = 1;
                Anslength = 3;
                CurrentLength = 3;
                AnsIndex = 1;
                //printf("hit6 \n");
	            fgSkip = 1;
	            //printf("hit4 \n");
	            if (*CurChar ==  *(CurChar - 1)) {
	                fgPalindromeStarts = 1; 
	                fgAns1CharRepeat = 1;
	            }
	            else {
	                fgAns1CharRepeat = 0; 
	                fgPalindromeStarts = 1; 
	            }
	        }
	        else if (*CurChar ==  *(CurChar - 1)){
	            Anslength = 2;
	            AnsIndex = 1;
	            RefIndex = 1;
				//fgAns1CharRepeat = 1;
	            //printf("hit2 \n");
	            fgPalindromeStarts = 1;
	            fgSkip = 1;
	        }
	        else {
	            fgPalindromeStarts = 0;
	            fgAns1CharRepeat = 0;
	            CurrentLength = 0;
	        }
	    }
	    else{
            if (fgAns1CharRepeat) {
                //printf("hit fgAns1CharRepeat %d\n", RefIndex);
                if ( *(CurChar - 1) == *CurChar) {
                    CurrentLength ++;
                    RefIndex += CurrentLength % 2 == 0? 0:1;
                }
                else {
                    bool fgIsAnsEven = 0;
                    if (CurrentLength % 2 == 0)
                        fgIsAnsEven = 1;
                    temp = (Index - RefIndex);
                    fgAns1CharRepeat = 0;    
                    //printf("hit check %c == %c temp %d RefIndex %d fgIsAnsEven %d \n",*(s + RefIndex - temp), *CurChar, temp , RefIndex ,fgIsAnsEven);
                    if ( *(s + fgIsAnsEven + RefIndex - temp) == *CurChar) {
                        CurrentLength += 2;
                        //printf("hit44 %c == %c\n",*(s + fgIsAnsEven + RefIndex - temp), *CurChar );
                    }
                    else {
                        fgAns1CharRepeat = 0;
                        fgPalindromeStarts = 0; 
                    }
                }
            }
            else if (fgPalindromeStarts && !fgSkip) {
                if ( (Index - RefIndex > RefIndex && (CurrentLength % 2 != 0))
                || (Index - RefIndex - 1 > RefIndex && (CurrentLength % 2 == 0))) {
                    //printf("hit bound Index %d, RefIndex %d \n", Index, RefIndex);

					/*if ( *(CurChar - 1) == *CurChar && !fgSubPalindromeStarts) {
                        fgPalindromeStarts = 1;
                        CurrentLength = 2;
                        RefIndex = Index - 1;
                        //printf("start new check\n");
                    }*/
                    if (fgSubPalindromeStarts){
						bool fgIsAnsEven = 0;
						if (TmpCurrentLength % 2 == 0)
							fgIsAnsEven = 1;
						temp = (Index - TmpRefIndex);
						fgAns1CharRepeat = 0; 
						//printf("hit 183 Index %d, RefIndex %d fgIsAnsEven %d, TmpRefIndex %d, temp %d  \n", Index, RefIndex, fgIsAnsEven, TmpRefIndex, temp);
						if ( *(s + fgIsAnsEven + TmpRefIndex - temp) == *CurChar) {
							//temp = RefIndex;
							RefIndex = TmpRefIndex;
							//TmpRefIndex = temp;
							//temp = TmpCurrentLength;
							CurrentLength = TmpCurrentLength;
							TmpCurrentLength = temp;
							CurrentLength += 2;
							//printf("hit5566 %c == %c TmpRefIndex %d\n",*(s + fgIsAnsEven + RefIndex - temp), *CurChar, TmpRefIndex );
						}
						fgSubPalindromeStarts = 0;

                    }
					else {
						fgSubPalindromeStarts = 0;
						fgPalindromeStarts = 0;
						CurrentLength = 0;
						RefIndex = Index;
					}
					/*if (*(CurChar) == *(CurChar - 2)) {
						fgSubPalindromeStarts = 1;
						TmpRefIndex = Index - 1;
						TmpCurrentLength = 3;
						//printf("store for new check 1\n");
					}*/
                }
                else {
                    bool fgIsAnsEven = 0;
                    if (CurrentLength % 2 == 0)
                        fgIsAnsEven = 1;
                    temp = (Index - RefIndex);
                    fgAns1CharRepeat = 0;    
                    //printf("hit check %c == %c temp %d RefIndex %d fgIsAnsEven %d \n",*(s + fgIsAnsEven + RefIndex - temp), *CurChar, temp , RefIndex ,fgIsAnsEven);
                    if ( *(s + fgIsAnsEven + RefIndex - temp) == *CurChar) {
                        CurrentLength += 2;
                        //printf("hit44 %c == %c\n",*(s + fgIsAnsEven + RefIndex - temp), *CurChar );
						if (*(CurChar) == *(CurChar - 2) && !fgSubPalindromeStarts) {
							TmpRefIndex = Index - 1;;
							TmpCurrentLength = 3;
							//printf("store for new check 2\n");
						}
						else if (fgSubPalindromeStarts) {
							fgIsAnsEven = 0;
							if (TmpCurrentLength % 2 == 0)
								fgIsAnsEven = 1;
							temp = (Index - TmpRefIndex);
							fgAns1CharRepeat = 0; 
							////printf("hit 183 Index %d, RefIndex %d fgIsAnsEven %d, TmpRefIndex %d, temp %d  \n", Index, RefIndex, fgIsAnsEven, TmpRefIndex, temp);
							//printf("hit11115566 %c == %c TmpRefIndex %d\n",*(s + fgIsAnsEven + RefIndex - temp), *CurChar, TmpRefIndex );
							if ( *(s + fgIsAnsEven + TmpRefIndex - temp) == *CurChar) {
								TmpCurrentLength += 2;
								//printf("hit11115566 %c == %c TmpRefIndex %d\n",*(s + fgIsAnsEven + RefIndex - temp), *CurChar, TmpRefIndex );
							}
							else {
								fgSubPalindromeStarts = 0;
								TmpRefIndex = 0;
								TmpCurrentLength = 0;
								//printf("sub string fail 222 \n");
								
							}
						}
                    }
					else if ( !fgIsAnsEven && *(s + 1 + RefIndex - temp) == *CurChar
						&& *(s + 1 + RefIndex - temp + 1) == *(CurChar - 1 )  ) {
						CurrentLength++;
                        //printf("hit444242 %c == %c\n",*(s + 1 + RefIndex - temp), *CurChar );
						if (*(CurChar) == *(CurChar - 2) && !fgSubPalindromeStarts) {
							TmpRefIndex = Index - 1;;
							TmpCurrentLength = 3;
							fgSubPalindromeStarts = 1;
							//printf("store for new check 2\n");
						}
						else if (fgSubPalindromeStarts) {
							fgIsAnsEven = 0;
							if (TmpCurrentLength % 2 == 0)
								fgIsAnsEven = 1;
							temp = (Index - TmpRefIndex);
							fgAns1CharRepeat = 0; 
							////printf("hit 183 Index %d, RefIndex %d fgIsAnsEven %d, TmpRefIndex %d, temp %d  \n", Index, RefIndex, fgIsAnsEven, TmpRefIndex, temp);
							//printf("hit11115566 %c == %c TmpRefIndex %d\n",*(s + fgIsAnsEven + RefIndex - temp), *CurChar, TmpRefIndex );
							if ( *(s + fgIsAnsEven + TmpRefIndex - temp) == *CurChar) {
								TmpCurrentLength += 2;
								//printf("hit11115566 %c == %c TmpRefIndex %d\n",*(s + fgIsAnsEven + RefIndex - temp), *CurChar, TmpRefIndex );
							}
							else {
								fgSubPalindromeStarts = 0;
								TmpRefIndex = 0;
								TmpCurrentLength = 0;
								//printf("sub string fail 222 \n");
								
							}
						}
					}
					else if (fgSubPalindromeStarts) {
						//printf("org string failed, use sub string check 111\n");
						/*sub string sucess*/
						bool fgIsAnsEven = 0;
						if (TmpCurrentLength % 2 == 0)
							fgIsAnsEven = 1;
						temp = (Index - TmpRefIndex);
						fgAns1CharRepeat = 0; 
						//printf("hit 183 Index %d, RefIndex %d fgIsAnsEven %d, TmpRefIndex %d, temp %d  \n", Index, RefIndex, fgIsAnsEven, TmpRefIndex, temp);
						if ( *(s + fgIsAnsEven + TmpRefIndex - temp) == *CurChar) {
							//temp = RefIndex;
							RefIndex = TmpRefIndex;
							//TmpRefIndex = temp;
							//temp = TmpCurrentLength;
							CurrentLength = TmpCurrentLength;
							TmpCurrentLength = temp;
							CurrentLength += 2;
							//printf("sub string sucess %c == %c TmpRefIndex %d\n",*(s + fgIsAnsEven + RefIndex - temp), *CurChar, TmpRefIndex );
						}
						fgSubPalindromeStarts = 0;
					}
                    else {
					
                        /*if ( *(CurChar - 1) == *CurChar) {
                            //printf("hit8\n");
                            fgPalindromeStarts = 1;
            	            CurrentLength = 2;
            	            RefIndex = Index - 1;
                        } 
                        else */ {
                            //printf("hit9\n");
            	            fgPalindromeStarts = 0;
            	            CurrentLength = 0;
            	            RefIndex = Index;
                        }
                    }
                }
                    
            }	        
    	    if (!fgPalindromeStarts  && !fgSkip)
    	    {   
				fgSubPalindromeStarts = 0;
        	    if (Index >= 2) {

        	        if (*(CurChar) == *(CurChar - 2)) {
        	            //printf("hit1 %d, %d, %c, %c\n",RefIndex, fgPalindromeStarts, *CurChar, *(CurChar -1));
                        RefIndex = Index - 1;
        	            CurrentLength = 3;
        	            fgPalindromeStarts = 1;
        	            fgSkip = 1;
        	        }
					else if (*CurChar == *(CurChar - 1)) {
        	            RefIndex = Index - 1;
        	            CurrentLength = 2;
        	            fgPalindromeStarts = 1;
        	            fgSkip = 1;
        	            //fgAns1CharRepeat = 1;
        	            //printf("hit0 %d, %d, %c, %c\n",RefIndex, fgPalindromeStarts, *CurChar, *(CurChar -1));
        	        }
        	    }
    	    }
    	    
	    }
	    if (Anslength < CurrentLength) {
            Anslength = CurrentLength;
            AnsIndex = RefIndex;
	    }
		Index++;
		CurChar++;
	}
    //if (Index >= 998 && (  *(s + 99) == 'a' || *(s + 997) == 'b') )
        //return s;
    if (Anslength == 0) {
        if(Index)
            *(s + 1) = 0;
        AnsChar = s;
    }
    else if (Anslength %2 == 0) {
        AnsChar = s + AnsIndex + 1 - Anslength/2; 
        *(s + AnsIndex + Anslength/2 + 1) = 0;
    }
    else {
        AnsChar = s + AnsIndex - Anslength/2; 
        *(s + AnsIndex + Anslength/2 + 1) = 0;
    }
	//printf("\n");
	//printf("AnsIndex %d Anslength %d \n",AnsIndex, Anslength);
	return AnsChar;
}
