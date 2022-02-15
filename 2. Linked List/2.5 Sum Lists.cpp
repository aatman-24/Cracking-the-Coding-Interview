#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007
#define eps 1e-6

using namespace std;


typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef map<int,int> mii;


/*
==============================> Description <=============================================

Question : 2.5 Sum Lists.
         - Perform addition on Linked List and return new Linked List. 
         - Digit in reverse order.
         - (follow up) Digit in forward order.

Topic : Linked List

Problems : 

==============================> Explanation <=============================================
- Reverse order, direct perform summation keep track of carry and sum value.

- Forward order,

    - First pad smaller LinkedList with value 0.
    - After perform the sum in reverse manner. Using recursion go to the tell and then come to the forward.

==============================> Apporach and Time Complexity <=============================================

1) Stack and Queue
Time: O(N)
Space: O(1)

*/

// Recursive Version....
// If LL is already in reverse order.. and return LL is also in reverse order.
ListNode* addList(ListNode* head1, ListNode *head2, int carry=0) {

    if(head1 == nullptr && head2 == nullptr && carry == 0) {
        return nullptr;
    }

    // create new node.
    ListNode* node = new ListNode();
    node->val = carry;

    if(head1 != nullptr)
        node->val += head1->val;

    if(head2 != nullptr)
        node->val += head2->val;

    carry = node->val / 10;

    node->val = node -> val % 10;

    if(head1 != nullptr || head2 != nullptr) {

        node -> next addList(head1 == nullptr ? head1 :  head1 -> next, head2 == nullptr ? head2 : head2->next, carry);
    }

    return node;
}


// Iterative version....
// Leetcode- 2   Add Two Numbers
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    ListNode* dummy = new ListNode(-1);
    ListNode* head = dummy;

    int carry = 0, sum = 0;

    while(l1 != NULL || l2 != NULL || carry) {

        sum = carry;

        if(l1 != NULL) {
            sum += l1->val;
            l1 = l1 -> next;
        }

        if(l2 != NULL) {
            sum += l2 -> val;
            l2 = l2 -> next;
        }

        carry = sum / 10;
        ListNode* newNode = new ListNode(sum % 10);
        dummy -> next = newNode;
        dummy = dummy -> next;  
    }

    return head -> next;

    }

};



// (follow up) Given LL is in forward....
// store the next pointer and carry value.
class PartialSum {
public:
    ListNode* next = nullptr;
    int carry = 0;
}


// find length.
int length(ListNode* node) {
    int count=0;
    while(node != nullptr) {
        count++;
        node = node -> next;
    }
    return count;
}



// padList with value 0 for padding times.
ListNode* padList(ListNode* l, int padding) {

    ListNode* head = l;
    for(int i = 0; i < padding; i++) {
        head = insertBefore(head, 0);
    }

    return head;
}

// create a new node with given value, and add before the given head node.
ListNode* insertBefore(ListNode* head, int value) {
    ListNode* node = new ListNode(value);
    if(head != nullptr)
        node->next = head;
    return node;
}


// Recursively add both the list.
PartialSum* addListHelper(ListNode* head1, ListNode* head2) {
    
    if(head1 == nullptr && head2 == nullptr) {
        // return empty list.
        PartialSum* sum = new PartialSum();
        return sum;
    }


    PartialSum* sum = addListHelper(head1->next, head2->next);

    // total the value.
    int val = sum->carry + head1->val + head2->val;

    // insert val % 10 new node before the sum->next node.
    ListNode* full_result = insertBefore(sum->next, val % 10);

    // store make the linking.
    sum->next = full_result;
    sum->carry = val / 10;

    // return sum node.
    return sum;
}



ListNode* addList(ListNode* l1, ListNode* l2) {

    // find both list length.
    int len1 = length(l1);
    int len2 = length(l2);

    // add padding with value 0 into the smaller list.
    if(len1 < len2) {
        l1 = padList(l1, len2-len1);
    }
    else {
        l2 = padList(l2, len1-len2);
    }   

    // get the sum node.
    PartialSum* sum = addListHelper(l1, l2);


    // if no carry then return list head. Otherwise add the carry node and after return that node.
    if(sum->carry == 0)     {
        return sum->next;
    }
    else {
        ListNode* head = insertBefore(sum->next, sum->carry);
        return head;
    }

}