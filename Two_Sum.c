//4ms beats 88%
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_VALUE   9999
#define MAX_AR_SIZE 40000 
int ans[2] = {0};

int* twoSum(int* nums, int numsSize, int target) {
    
    int Hash[MAX_AR_SIZE] = {MAX_VALUE};
    int NegHash[MAX_AR_SIZE] = {MAX_VALUE};
    int FirstApeerOfHash[MAX_AR_SIZE] = {MAX_VALUE};
    int NegFirstApeerOfHash[MAX_AR_SIZE] ={MAX_VALUE};
    int index = 0;
    bool fgIsAnsValid = 0;
    
    if(nums[0]==-1 && nums[1]== -2){
        fgIsAnsValid = 1;
    }
    
    for(index = 0; index <= MAX_AR_SIZE; index++ ){
        Hash[index] = MAX_VALUE;
        NegHash[index] = MAX_VALUE;
        FirstApeerOfHash[index] = MAX_VALUE;
        NegFirstApeerOfHash[index]= MAX_VALUE;        
    } 

    //ans

    //return ans;

    for (index = 0; index < numsSize; index++ ){
        if(nums[index] > 0){
            Hash[nums[index]] = index;
            if(FirstApeerOfHash[nums[index]]==MAX_VALUE)
                FirstApeerOfHash[nums[index]]= index;
        }
        else if (nums[index] < 0){
            NegHash[0- nums[index] ] = index;
            if(NegFirstApeerOfHash[0 - nums[index]]==MAX_VALUE)
                NegFirstApeerOfHash[0 - nums[index]]= index;
        }
        else{ //nums[index] == 0
            Hash[nums[index]] = index;
            if(FirstApeerOfHash[nums[index]]==MAX_VALUE)
                FirstApeerOfHash[nums[index]]= index;
                
            NegHash[0- nums[index] ] = index;
            if(NegFirstApeerOfHash[0 - nums[index]]==MAX_VALUE)
                NegFirstApeerOfHash[0 - nums[index]]= index;            
        }
    }

                   if(fgIsAnsValid){
                    //ans[0]=222 ;index; ans[1] = 111 ;Hash[index];
                    //return ans;
                 }

    #if 1

    for(index = 0; index < MAX_AR_SIZE; index++){
        if(target > index ){
            if( Hash[index] != MAX_VALUE){
                if( Hash[target-index] != MAX_VALUE ){
                    if(Hash[index] > Hash[target-index] ){
                        ans[0] = Hash[target-index]+1;
                        ans[1] = Hash[index]+1;
                        return ans;
                    }
                    else if(Hash[index] < Hash[target-index] ){
                        ans[1] = Hash[target-index]+1;
                        ans[0] = Hash[index]+1;
                        return ans;
                    }
                    else{
                        ans[0] = FirstApeerOfHash[index] + 1;
                        ans[1] = Hash[index] + 1;
                        return ans;
                    }
                }
            }
        }
        else if(target < index ){
             if( Hash[index] != MAX_VALUE  ){ // positive + negtive case
                if( NegHash[index-target] != MAX_VALUE ){
                    if(Hash[index] > NegHash[index-target] ){
                        ans[0] = NegHash[index-target]+1;
                        ans[1] = Hash[index]+1;
                        return ans;
                    }
                    else if(Hash[index] < NegHash[index-target] ){
                        ans[1] = NegHash[index-target]+1;
                        ans[0] = Hash[index]+1;
                        return ans;
                    }
                    else{
                        //ans[0] = FirstApeerOfHash[index] + 1;
                        //ans[1] = Hash[index] + 1;
                    }
                }
            }
            else if( NegHash[index] != MAX_VALUE){
                if(fgIsAnsValid){
                    //ans[0]=index; ans[1] = Hash[index];
                    //return ans;
                 }
                if( NegHash[(0-target)-index] != MAX_VALUE ){
                    if(NegHash[index] > NegHash[(0-target)-index] ){
                        ans[0] = NegHash[(0-target)-index]+1;
                        ans[1] = NegHash[index]+1;
                        return ans;
                    }
                    else if(NegHash[index] < NegHash[(0-target)-index] ){
                        ans[1] = NegHash[(0-target)-index]+1;
                        ans[0] = NegHash[index]+1;
                        return ans;
                    }
                    else{
                        ans[0] = NegFirstApeerOfHash[index] + 1;
                        ans[1] = NegHash[index] + 1;
                        return ans;
                    }
                }
            }                
            
        }
        else{  //target == index
            if(target > 0){
                 if( Hash[index] != MAX_VALUE){
                    if( Hash[index-target] != MAX_VALUE ){
                        if(Hash[index] > Hash[target-index] ){
                            ans[0] = Hash[target-index]+1;
                            ans[1] = Hash[index]+1;
                            return ans;
                        }
                        else if(Hash[index] < Hash[target-index] ){
                            ans[1] = Hash[target-index]+1;
                            ans[0] = Hash[index]+1;
                            return ans;
                        }
                        else{
                            ans[0] = FirstApeerOfHash[index] + 1;
                            ans[1] = Hash[index] + 1;
                            return ans;
                        }
                    }
                } 
            }
            if (target == 0){
                  if( Hash[index] != MAX_VALUE){
                    if( Hash[index-target] != MAX_VALUE ){
                        if(Hash[index] > Hash[target-index] ){
                            ans[0] = Hash[target-index]+1;
                            ans[1] = Hash[index]+1;
                            return ans;
                        }
                        else if(Hash[index] < Hash[target-index] ){
                            ans[1] = Hash[target-index]+1;
                            ans[0] = Hash[index]+1;
                            return ans;
                        }
                        else{
                            ans[0] = FirstApeerOfHash[index] + 1;
                            ans[1] = Hash[index] + 1;
                            return ans;
                        }
                    }
                }               
            }
            if(target < 0){
                 if( NegHash[index] != MAX_VALUE){
                    if( NegHash[index-target] != MAX_VALUE ){
                        if(NegHash[index] > NegHash[target-index] ){
                            ans[0] = NegHash[target-index]+1;
                            ans[1] = NegHash[index]+1;
                            return ans;
                        }
                        else if(NegHash[index] < NegHash[target-index] ){
                            ans[1] = NegHash[target-index]+1;
                            ans[0] = NegHash[index]+1;
                            return ans;
                        }
                        else{
                            ans[0] = NegFirstApeerOfHash[index] + 1;
                            ans[1] = NegHash[index] + 1;
                            return ans;
                        }
                    }
                } 
            }
        }
    }
    #endif
    ans[0] = 1234567;
    ans[1] = 7654321;
    return ans;
}
