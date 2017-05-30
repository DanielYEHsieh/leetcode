//16ms beats 100%
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 #define TRUE 1
 #define FALSE 0
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* l1Current = l1;
    struct ListNode* l2Current = l2;
    struct ListNode* l1Prev = l1;
    struct ListNode* l2Prev = l2;    
    
    struct ListNode* lAns;
    bool fgIsLastNodeBiggerThan10 = FALSE;
    int l1Val = 0;
    int l2Val = 0;
    int l1Valplusl2Val;
    bool fgIsUsel1AsAnswer = TRUE;
    bool fgIsReturnDebug = FALSE;
    
    if(l1->val ==9 && l2->val ==1 ){
        if(l1->next){
           if( l1->next->val == 8)
            fgIsReturnDebug = TRUE;
        }
    }

    while (l1Current != NULL && l2Current != NULL){
        l1Valplusl2Val = l1Current->val + l2Current->val+ + fgIsLastNodeBiggerThan10;
        if(l1Valplusl2Val > 9 ){
            l1Valplusl2Val = l1Valplusl2Val - 10;
            fgIsLastNodeBiggerThan10 = TRUE;
        }
        else
            fgIsLastNodeBiggerThan10 = FALSE;        
        l1Current->val = l1Valplusl2Val;
        l2Current->val = l1Valplusl2Val;
 
        if(l1Current->next == NULL && l2Current->next != NULL){
            fgIsUsel1AsAnswer = FALSE;
            break;
        }
        else if(l2Current->next == NULL && l1Current->next != NULL){
            fgIsUsel1AsAnswer = TRUE;
            break;
        }
        else if(l2Current->next == NULL && l1Current->next == NULL){
            fgIsUsel1AsAnswer = FALSE;
            break;            
        }
        else {
            l1Current = l1Current->next;        
            l2Current = l2Current->next;
        }
    }
    if(fgIsUsel1AsAnswer){
        l1Current = l1Current->next;
        l1Valplusl2Val = l1Current->val + fgIsLastNodeBiggerThan10;
        if(l1Valplusl2Val > 9 ){
            l1Valplusl2Val = l1Valplusl2Val - 10;
            fgIsLastNodeBiggerThan10 = TRUE;
        }
        else {
          fgIsLastNodeBiggerThan10 = FALSE;  
        }
        l1Current->val = l1Valplusl2Val;        
        while(l1Current->next != NULL){
            l1Current = l1Current->next;
            l1Valplusl2Val = l1Current->val + fgIsLastNodeBiggerThan10;
            if(l1Valplusl2Val > 9 ){
                l1Valplusl2Val = l1Valplusl2Val - 10;
                fgIsLastNodeBiggerThan10 = TRUE;
            }
            else
                fgIsLastNodeBiggerThan10 = FALSE;            
            l1Current->val = l1Valplusl2Val;            
        }
        if(fgIsLastNodeBiggerThan10){
            l1Current->next = l2;
            l1Current->next->val = fgIsLastNodeBiggerThan10;
            l1Current->next->next = NULL;
            return l1;
        }else
            return l1;
    }
    else {
        if(l2Current->next != NULL){
            l2Current = l2Current->next;   
            l1Valplusl2Val = l2Current->val + fgIsLastNodeBiggerThan10;
            if(l1Valplusl2Val > 9 ){
                l1Valplusl2Val = l1Valplusl2Val - 10;
                fgIsLastNodeBiggerThan10 = TRUE;
            }
            else {
              fgIsLastNodeBiggerThan10 = FALSE;  
            }            
            l2Current->val = l1Valplusl2Val;            
            
            while(l2Current->next != NULL){
                l2Current = l2Current->next;
                l1Valplusl2Val = l2Current->val + fgIsLastNodeBiggerThan10;
                if(l1Valplusl2Val > 9 ){
                    l1Valplusl2Val = l1Valplusl2Val - 10;
                    fgIsLastNodeBiggerThan10 = TRUE;
                }
                else
                    fgIsLastNodeBiggerThan10 = FALSE;
                l2Current->val = l1Valplusl2Val;                
            }
            if(fgIsLastNodeBiggerThan10){
                l2Current->next = l1;
                l2Current->next->val = fgIsLastNodeBiggerThan10;
                l2Current->next->next = NULL;
                return l2;
            } 
            else
                return l2;            
        }
        else{

            
            if(fgIsLastNodeBiggerThan10){
                l2Current->next = l1;
                l2Current->next->val = fgIsLastNodeBiggerThan10;
                l2Current->next->next = NULL;
                return l2;
            } 
            else{
                return l2;
            }
        }
    }
    
}
