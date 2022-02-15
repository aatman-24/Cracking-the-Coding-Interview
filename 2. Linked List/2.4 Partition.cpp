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

Question : 2.4 Partition
          - Perform Partition on LL, such that value < x is follwed by value >= x.
        
            Ex... 1 -> 2 -> 5 -> 6 -> 3 -> 7  x = 5

                 In any order, one of them is... 1 -> 2 -> 3 -> 6 -> 5 -> 7



Topic : Stack & Queue
Problems : 

==============================> Explanation <=============================================

1st Approach:

- For parition of linkedlist with x value,

 we can create two linkedlist, 

 LL with value < x.
 LL with value >= x.

 and at the end we merge both the LL.


2nd Approach:

- Using single LL. we perform partition...

node value < x. we join the node at the head pointer (from right to left)
node value >= x. we join the node at the tail pointer (from left to right)


at the end we return the head pointer.


==============================> Apporach and Time Complexity <=============================================

1) Stack and Queue
Time: O(N)
Space: O(1)

*/

// order is important.
ListNode* partition(ListNode* node, int k) {

    ListNode *beforeHead = nullptr, *beforeEnd = nullptr;
    ListNode *afterHead = nullptr, *afterEnd = nullptr;

    while(node != nullptr) {

        ListNode* next = node -> next;

        if(node->val < k) {

            if(beforeHead == nullptr) {
                beforeHead = node;
                beforeEnd = node;
            }
            else {
                beforeEnd -> next = node;
                beforeEnd = node;
            }

        }

        else {

            if(afterHead == nullptr) {
                afterHead = node;
                afterEnd = node;
            }
            else {
                afterEnd -> next = node;
                afterEnd = node;
            }
        }

        node = next;

    }

    // no node value less than given value.
    if(beforeHead == nullptr)
        return afterHead;

    // merge both the link.
    beforeEnd -> next = afterHead;


    return beforeHead;
}


// optimized apporach. (Order is not important of element)
ListNode* partition(ListNode* node, int k) {

    ListNode* head = node;
    ListNode* tail = node;

    while(node != nullptr) {

        ListNode* next = node -> next;


        if(node -> val < x) {

            node -> next = head;
            head = node;

        }
        else {

            tail -> next = node;
            tail = node;
        }

        node = next;
    }

    return head;

}