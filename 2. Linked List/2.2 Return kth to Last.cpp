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

Question : 2.2 Return kth to Last
Topic : LinkedList
Problems : 

==============================> Explanation <=============================================

Approach 1-4: Take O(N) time and O(N) space.

Approach 5: Take O(N) time and O(1) space.
- Set both pointer to head.
- Move p1 to kth step forward.
- Now move both pointer until p1 become nullptr.
- Return p2.

p1 convers N distance. p2 covers N - K distance.


==============================> Apporach and Time Complexity <=============================================

1) LinkedList
Time: O(N)
Space: O(1)

*/

// 1) We print the last kth node value.
int printKthToLast(ListNode* head, int k) {
    if(head == nullptr)
        return 0;
    int index = printKthToLast(head->next, k) + 1;
    if(index == k) {
        cout << head->val << endl;
    }
    return index;
}


// 2) Return the node itself.
ListNode* KthToLast(ListNode* head, int k, int i) {
    if(head == nullptr)
        return nullptr;
    LisNode* node = KthToLast(head, k, i);
    i = i + 1;

    // we return the current node.
    
    if(i == k) {
        return head;
    }
    return node;
}

int KthToLast(ListNode* head, int k) {
    int i = 0;
    return KthToLast(head, k, i);
}

// 3) Same as 2. but with Index class. inplace of pass by reference.
class Index {
public:
    int value;
    Index(){
        value = 0;
    }
}

ListNode* KthToLast(ListNode *head, int k) {
    Index index;
    return KthToLast(head k, index);
}

ListNode* KthToLast(ListNode* head, int k, Index index) {
    if(head == nullptr)
        return nullptr;
    ListNode* node = KthToLast(head, k, index);
    index.value += 1;
    if(index.value == k) {
        return head;
    }
    return node;
}

// 4) We can use static varaible as well.


// 5) Optimized Apporach: Two pointer

ListNode* KthToLast(ListNode* head, int k) {

    ListNode* p1 = head;
    ListNode* p2 = head;

    for(int i = 0; i < k; i++) {
        if(p1 == nullptr)
            return nullptr;
        p1 = p1 -> next;
    }

    while(p1 != nullptr) {
        p1 = p1 -> next;
        p2 = p2 -> next;
    }

    return p2;
}