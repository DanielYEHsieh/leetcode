//42 ms beats 66% 
double MedOfArray (int* nums, int numsSize)
{
    bool fgIsEvenSize = numsSize % 2 == 0? 1:0;
    if(fgIsEvenSize) {
        int mid1, mid2;
        mid1 = numsSize/2 - 1;
        mid2 = numsSize/2;
        return((double)nums[mid1] + (double)nums[mid2] )/2; 
        
    }
    else
        return nums[(numsSize /2 )];
}


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {

    if(nums1Size > nums2Size)
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    if(nums1Size == 2 || nums1Size == 1) {
        if (nums1Size == 2) {
            //printf("%d,%d | %d,%d \n", nums1[0],nums1[1], nums2[0],nums2[1]);
            if (nums2Size == 2) {
                
                if(nums1[1] >= nums2[1]) {
                   //"?,? N2E, N1E" or "N2S ,N2E, N1S, N1E"
                    if(nums2[0] >= nums1[0])
                        return (double)(((double)nums2[0] + (double)nums2[1])/2);
                    else {
                        //printf("hit %d , %d \n",nums2[0],nums1[1]);
                        return (double)(((double)nums2[1] + (double)nums1[0])/2);
                    }
                }
                else {
                    // "?,? N1E, N2E" or "N1S ,N1E, N2S, N2E"
                    if(nums1[0] >= nums2[0]) {
                        return (double)(((double)nums1[0] + (double)nums1[1])/2);
                    }
                    else  {
                        return (double)(((double)nums2[0] + (double)nums1[1])/2);
                    }
                }
            }
            else {
                if (nums2Size % 2 == 0)
                {
                    int mid1, mid2;
                    mid1 = nums2Size/2 - 1;
                    mid2 = nums2Size/2;
                    if (nums2[mid2] >= nums1[1] ) {
                        if (nums1[1] >= nums2[mid1]) {
                            if (nums2[mid1] >= nums1[0])
                                return  (double)(((double)nums2[mid1] + (double)nums1[1])/2);
                            else
                                return (double)(((double)nums1[0] + (double)nums1[1])/2);
                        }
                        else {
                            if (nums1[1] >= nums2[mid1 - 1]) {
                                return  (double)(((double)nums2[mid1] + (double)nums1[1])/2);
                            }
                            else
                                return  (double)(((double)nums2[mid1] + (double)nums2[mid1 - 1])/2);
                        }
                    }
                    else { //nums2[mid2] < nums1[1]
                         if (nums1[0] >= nums2[mid2]) {
                            if (nums1[0] >= nums2[mid2 + 1]) {
                                return  (double)(((double)nums2[mid2] + (double)nums2[mid2 + 1])/2);
                            }
                            else
                                return  (double)(((double)nums2[mid2] + (double)nums1[0])/2);
                        }
                        else { // nums1[0] < nums2[mid2]
                            if (nums1[0] >= nums2[mid1]) {
                                return  (double)(((double)nums2[mid2] + (double)nums1[0])/2);
                            }
                            else
                                return  (double)(((double)nums2[mid2] + (double)nums2[mid1])/2);
                        }                       
                    }
                }
                else { // nums2Size %2 != 0;
                    int mid;
                    mid = nums2Size/2;
                    
                    if (nums2[mid] >= nums1[0] ) {
                        if (nums2[mid] <= nums1[1])
                            return nums2[mid];
                        else {
                            if (nums2[mid - 1] <= nums1[1])
                                return nums1[1];
                            else
                                return nums2[mid - 1];
                        }
                    }
                    else { //(nums2[mid] < nums1[0] )
                        if (nums2[mid + 1] <= nums1[0])
                            return nums2[mid + 1];
                        else
                            return nums1[0];
                    }
                }
            }
        }
        else { //nums1Size == 1
        //printf("%d,%d | %d,%d \n", nums1[0], nums2[0],nums2[1]);
            if (nums2Size == 2) {
                if(nums1[0] >= nums2[1]) {
                    return nums2[1];
                }
                else {
                    if(nums1[0] >= nums2[0])
                        return nums1[0];
                    else
                        return nums2[0];
                }
            }
            else if (nums2Size == 1) {
                return (double)(((double)nums2[0] + (double)nums1[0])/2);
            }
            else {
                if (nums2Size % 2 == 0)
                {
                    int mid1, mid2;
                    mid1 = nums2Size/2 - 1;
                    mid2 = nums2Size/2;
                    if (nums2[mid2] >= nums1[0] ) {
                        if (nums1[0] >= nums2[mid1])
                            return nums1[0];
                        else
                            return nums2[mid1];
                    }
                    else
                        return nums2[mid2];
                }
                else { // nums2Size %2 != 0;
                    int mid;
                    mid = nums2Size/2;

                    if (nums2[mid] >= nums1[0] ) {
                        if (nums2[mid -1 ] <= nums1[0])
                            return (double)(((double)nums2[mid] +(double) nums1[0])/2);
                        else
                            return (double)(((double)nums2[mid] + (double)nums2[mid - 1])/2);
                    }
                    else { //(nums2[mid] < nums1[0] )
                        if (nums2[mid + 1] <= nums1[0])
                            return (double)(((double)nums2[mid] + (double)nums2[mid + 1])/2);
                        else
                            return (double)(((double)nums2[mid] + (double)nums1[0])/2);
                    }
                }
            }
        }
    }

    else if(nums1Size == 0 && nums2Size == 0)
        return 0;
    else if (nums1Size == 0 && nums2Size != 0)
        return MedOfArray(nums2,nums2Size);
    else {
        int mid11,mid12,mid21, mid22;
        int mid1, mid2;
        
        bool fgEve1, fgEve2;
        fgEve1 = fgEve2 = 0;
        
        if (nums1Size %2 == 0) {
            fgEve1 = 1;
            mid11 = nums1Size/2 - 1;
            mid12 = nums1Size/2;
        }
        else {
            mid1 = nums1Size/2 ;
        }
        if (nums2Size %2 == 0){
            fgEve2 = 1;
            mid21 = nums2Size/2 - 1;
            mid22 = nums2Size/2;
        }
        else {
            mid2 = nums2Size/2;
        }
        if(MedOfArray(nums1,nums1Size) == MedOfArray(nums2,nums2Size))
            return MedOfArray(nums1,nums1Size);
        else {

            if (fgEve1 && fgEve2) {
                if(nums2[mid21] >= nums1[mid11]) {
                    if(nums1[mid12] >= nums2[mid21]) {
                        if(nums1[mid12] >= nums2[mid22])
                            return (double)(((double)nums2[mid21] + (double)nums2[mid22])/2);
                        else
                            return (double)(((double)nums2[mid21] + (double)nums1[mid12])/2);
                    }
                    else { //(nums2[mid21] > nums1[mid12])
                        return findMedianSortedArrays(&nums1[mid11], nums1Size - nums1Size/2 + 1 , nums2, nums2Size - nums1Size/2 + 1 );
                    }
                }
                else { //nums1[mid11] > nums2[mid21]
                    if(nums2[mid22] >= nums1[mid11]) {
                        if(nums2[mid22] >= nums1[mid12])
                            return (double)(((double)nums1[mid11] + (double)nums1[mid12])/2);
                        else
                            return (double)(((double)nums1[mid11] + (double)nums2[mid22])/2);
                    }
                    else { //(nums1[mid11] > nums2[mid22])
                        return findMedianSortedArrays(nums1, nums1Size - nums1Size/2 + 1 , &nums2[mid11], nums2Size - nums1Size/2 + 1 );
                    }
                }
            }
            else if (fgEve1 && !fgEve2) {
                if(nums2[mid2] >= nums1[mid11]) {
                    if(nums1[mid12] >= nums2[mid2]) {
                        return nums2[mid2];
                    }
                    else { //(nums2[mid2] > nums1[mid12])
                        return findMedianSortedArrays(&nums1[mid11], nums1Size - nums1Size/2 + 1 , nums2, nums2Size - nums1Size/2 + 1 );
                    }
                }
                else { //nums1[mid11] > nums2[mid2]
                    return findMedianSortedArrays(nums1, nums1Size - nums1Size/2 + 1 , &nums2[mid11], nums2Size - nums1Size/2 + 1 );
                }
            }
            else if (!fgEve1 && fgEve2){
                if(nums1[mid1] >= nums2[mid21]) {
                    if(nums2[mid22] >= nums1[mid1]) {
                        return nums1[mid1];
                    }
                    else { //(nums1[mid1] > nums2[mid22])
                        return findMedianSortedArrays(nums1, nums1Size - nums1Size/2 , &nums2[mid1], nums2Size - nums1Size/2 );
                    }
                }
                else { //nums1[mid11] > nums2[mid2]
                    return findMedianSortedArrays(&nums1[mid1], nums1Size - nums1Size/2 , nums2, nums2Size - nums1Size/2 );
                }
            }
            else {
                //printf("%d,%d,%d,%d,%d,%d \n",nums1[mid1],nums2[mid2],mid1,mid2,nums1Size - nums1Size/2,nums2Size - nums1Size/2);
                if(nums2[mid2] >= nums1[mid1]) {
                    return findMedianSortedArrays(&nums1[mid1], nums1Size - nums1Size/2 , nums2, nums2Size - nums1Size/2 ); 

                }
                else { //nums1[mid1] > nums2[mid2]
                    return findMedianSortedArrays(nums1, nums1Size - nums1Size/2 , &nums2[mid1], nums2Size - nums1Size/2 );
                }
            }
        }
    }

    return 0;
}








