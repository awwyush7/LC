/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*t1=l1,*t2=l2;
        int n1=0,n2=0;
        while(t1){
            n1++;
            t1=t1->next;
        }
        while(t2){
            n2++;
            t2=t2->next;
        }
        if(n2>n1){
            ListNode*tem;
            tem=l1;
            l1=l2;
            l2=tem;
        }
        ////////////////////////////////////////////
        ListNode*tt1=l1,*tt2=l2,*p1,*p2;
        int sum=0,carry=0;
        int v1,v2;
        while(tt1!=NULL || tt2!=NULL){
            if(tt2==NULL){
                v2=0;
            }else v2=tt2->val;
            if(tt1==NULL){
                v1=0;
            }else v1=tt1->val;
            
            sum=v1+v2+carry;
            
            if(sum<10){
                tt1->val=sum;
                carry=0;
            }
            else{
                tt1->val=sum%10;
                carry=sum/10;
            }
           if(tt1!=NULL) p1=tt1;
            if(tt2!=NULL) p2=tt2;
            if(tt1!=NULL) tt1=tt1->next;
            if(tt2!=NULL) tt2=tt2->next;
            
        }
        if(carry!=0){
            ListNode* ttt=new ListNode();
            ttt->val=carry;
            p1->next=ttt;
        }
        
        return l1;
    }
};