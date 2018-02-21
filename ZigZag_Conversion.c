#define UP 1
#define DOWN 2

char* convert(char* s, int numRows) {
    int len = strlen(s);
    char *rZigZag = NULL;
    int *MoreData = NULL;
    int *Offset = NULL;
    int i = 0;
    int j = 0;
    int counter = 0;
    int Index = 0;

    int Dir = DOWN;
    rZigZag = malloc((len + 1) * sizeof(char));
    memset(rZigZag, 0, len * sizeof(char));
    MoreData = malloc(numRows * sizeof(int));
    memset(MoreData, 0, numRows * sizeof(int));
    Offset = malloc(numRows * sizeof(int));
    memset(Offset, 0, numRows * sizeof(int));
    
    rZigZag[0] = s[0];
    if (len < 3 || numRows < 2 || numRows >= len)
        return s;
    i = 0;
    counter = 0;

    while (len > i) {
        //printf("counter %d\n", counter);
        if (Dir == DOWN) {
            //printf("i %d more data index %d\n", i, counter);
            MoreData[counter]++;
            if (counter == (numRows - 1)){
                if (numRows > 2) {
                    Dir = UP;
                    counter = 1;
                }
                else{
                    Dir = DOWN;
                    counter = 0;
                }
            }
            else
                counter++;
        }
        else {
            //printf("i %d more data index %d\n", i, numRows - 1 - counter);
            MoreData[numRows -1 - counter]++;
            if (counter == numRows - 2) {
                Dir = DOWN;
                counter = 0;
            }
            else
                counter++;
        }
        i++;
    }
    int sum = MoreData[0];
    MoreData[0] = 0;
    //printf("i %d : %d\n",0, MoreData[0]);
    int temp = 0;
    for (i = 1; i < numRows; i++){
        temp = MoreData[i];
        MoreData[i] = sum;
        //printf("i %d : %d\n",i, MoreData[i]);
        sum += temp;
    }
    i = 0;
    counter = 0;
    Dir = DOWN;
    while (len > i) {
        //printf("s[%d]%c\n",i,s[i]);
        if (Dir == DOWN) {

          //  printf("zigzag index %d assgin %c s[%d]\n", Offset[counter] + MoreData[counter], s[i], i);
            rZigZag[Offset[counter] + MoreData[counter ]]  = s[i];  

            //printf("row %d \n", counter);
            Offset[counter]++;
            if (counter == (numRows - 1)){
                if (numRows > 2) {
                    Dir = UP;
                    counter = 1;
                }
                else{
                    Dir = DOWN;
                    counter = 0;
                }
            }
            else
                counter++;
        }
        else {
            //printf("UP zigzag index %d more data assgin %c s[%d]\n", 
              //     Offset[numRows -1 - counter] + MoreData[numRows -1 - counter], s[i], i);
            rZigZag[Offset[numRows -1 - counter] + MoreData[numRows -1 - counter]]  = s[i];  
            //printf("row %d \n", numRows -1 - counter);
            Offset[numRows -1 - counter]++;            
            if (counter == numRows - 2) {
                Dir = DOWN;
                counter = 0;
            }
            else
                counter++;
        }
        i++;
    }
    //for (i = 0; i < len; i++)
      //  printf("%c", rZigZag[i]);
    rZigZag[len] = 0;
    return rZigZag;
}
