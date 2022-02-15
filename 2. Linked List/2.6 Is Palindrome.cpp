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

Question : 2.5 Is Palindrome
Topic : Stack and Recursion
Problems : 

==============================> Explanation <=============================================

check all the approach.

- reverse + clone
- stack (Iterative)
- recurison with help of pass by reference

==============================> Apporach and Time Complexity <=============================================

1) All Approach
Time: O(N)
Space: O(N)

*/

// 1st Approach: Make clone of current LL in reverse form, and compare both.
bool isPalindrome(ListNode* head) {
    ListNode* reversed = reverseAndClone(head);
    return isEqual(head, reversed);
}

ListNode* reverseAndClone(ListNode* node) {
    ListNode* head = nullptr;
    while(node != nullptr) {
        ListNode* n = new ListNode(node->val);
        n->next = head;
        head = n;
        node = node->next;
    }
    return head;
}

bool isEqual(ListNode* one, ListNode* two) {
    while(one != nullptr && two != nullptr) {
        if(one->val != two->val) {
            return false;
        }
        one = one->next;
        two = two->next;
    }
    return one == nullptr && two == nullptr;
}



// 2nd Apporach: Using Stack. Add half of LL in stack and after compare with st.top().
bool isPalindrome(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    // reach the middle of LL.
    while(fast != nullptr && fast->next != nullptr) {
        st.push(slow->val);
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    // odd number of nodes.
    if(fast != nullptr)
        fast = fast -> next;


    while(slow != nullptr) {
        int top = st.top(); st.pop();
        // st->top and slow->val must be same.
        if(slow->val != top)
            return false;
        slow = slow -> next;
    }

    return true;
}


// 3rd Approach: Use the recursion as stack.
// (NOTE): In java pass by reference is not possible for that reason we have to use another class instance
           // to keep track of data.
        
    // class Result {
    // public:
    //     ListNode* node;
    //     bool res;
    // }


bool isPalindrome(ListNode* leftNode, ListNode* &rightNode, int length) {
    
    if(length == 0) {
        rightNode = leftNode;
        return true;
    }
    else if(length == 1) {
        rightNode = leftNode -> next;
        return true;
    }

    bool res = isPalindrome(leftNode->next, rightNode, length-2);

    res = res & (leftNode->val == rightNode -> val); 

    rightNode = rightNode -> next;

    return res;
}

int lengthOfList(ListNode* head) {
    int count = 0;
    while(head != nullptr) {
        head = head -> next;
        count++;
    }
    return count;
}

bool isPalindrome(ListNode* head) {

    ListNode* rightNode = nullptr;
    int length = lengthOfList(head);

    return isPalindrome(head, rightNode, length);
}