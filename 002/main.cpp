struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
      };
class Solution {
public:
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3=new ListNode();
        ListNode* iterator=l3;
        while(l1!= nullptr||l2!= nullptr){
            int k;
            if(l1== nullptr){
                k=l2->val;
            }else if(l2== nullptr){
                k=l1->val;
            }else{
                k=l1->val+l2->val;
            }
            k=k+l3->val;
            if(k>=10){
                l3->next=new ListNode();
                l3->val=k-10;
                l3=l3->next;
                l3->val=k/10;
            }else{
                l3->next=new ListNode();
                l3->val=k;
                l3=l3->next;
            }
            if(l1== nullptr){
                l2=l2->next;
            }else if(l2== nullptr){
                l1=l1->next;
            }else{
                l1=l1->next;
                l2=l2->next;
            }
        }
        ListNode* iterator2=iterator;
        ListNode* iterator3=iterator;
        iterator3=iterator3->next;

        while(iterator2->next!= nullptr){
            if(iterator3->val==0&&iterator3->next== nullptr){
                iterator2->next=nullptr;
                break;
            }
            iterator2=iterator2->next;
            iterator3=iterator3->next;
        }
        return iterator;
    }
};

int main (){
    ListNode* l1=new ListNode(1);
    l1->next=new ListNode(2);//21
    ListNode* l2=new ListNode(2);
    l2->next=new ListNode(9);
    l2->next->next=new ListNode(6);//692
    ListNode* l3=Solution::addTwoNumbers(l1,l2);

}
