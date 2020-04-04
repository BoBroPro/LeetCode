#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
};
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* rp = head;
    ListNode* lp;
    ListNode* tmp;
    for(int i = 0;i<n; ++i){
        if( !(rp) ){
            return head;
        }
        rp = rp->next; 
    }
    if(!rp){
        tmp = head;
        head = head->next;
        delete tmp;
        return head;
    }

    rp = rp->next;
    lp = head;
    for(;rp;){
        rp = rp->next;
        lp = lp->next;
    }
    tmp = lp->next;
    lp->next= lp->next->next;
    delete tmp;
    return head;  
}

void printL(const ListNode*p){
    for(;p;){
        cout<<p->val;
        p=p->next;
    }
    cout <<endl;
}

int main(){
    ListNode* lhead = new ListNode(0);
    ListNode* l = lhead;
    for(int i = 1; i<10; ++i){

        l->next =new ListNode(i);
        l = l->next;
    }
    l = nullptr;
    lhead = removeNthFromEnd(lhead,4);

    printL(lhead);
    getchar();
}
