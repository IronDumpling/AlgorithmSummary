//
// Created by 张楚岳 on 2021-09-08.
//
#include <vector>

/*
 * Method 1.
 * FAST AND SLOW POINTERS
 * Is used to deal with List
 * */
struct ListNode{
    int val;
    ListNode *next;
    ListNode();
    ListNode(int x): val(x), next(nullptr){}
};

// Function 1: Detect if there is cycle in List
bool hasCircle(ListNode* head){
    // Step 1. Initialise two pointers, both point to head
    ListNode *fast = head, *slow = head;

    // Step 2. until fast or the next of fast point to the end
    while(fast != nullptr && fast->next != nullptr){
        // Step 2.1 fast traverses two nodes
        fast = fast->next->next;
        // Step 2.2 slow traverses one node
        slow = slow->next;
        // Step 2.3 two pointers meet
        if(fast == slow) return true;
    }

    // Step 3. If meets the end, means no circle
    return false;
}

// Function 2: Find the Start Node of Cycle
ListNode* detectCycleStart(ListNode* head){
    // Step 1. Initialise two pointers, both point to head
    ListNode *fast = head, *slow = head;

    // Step 2. until fast or the next of fast point to the end
    while(fast != nullptr && fast->next != nullptr){
        // Step 2.1 fast traverses two nodes
        fast = fast->next->next;
        // Step 2.2 slow traverses one node
        slow = slow->next;
        // Step 2.3 two pointers meet, which means cycle exists
        if(fast == slow) break;
    }

    // Step 3. FInd Start Node of the Cycle
    // Since slow moves k steps and fast moves 2k steps, the cycle has 2k - k = k steps
    // Hence, the distance between head and meeting point is the same as meeting point and itself going through the cycle
    // Therefore, the node number between the head and the start node is the same as it between the meeting node and start node
    // Step 3.1 Initialise slow to the head
    slow = head;

    //Step 3.2 Move both pointers one step forward
    while(slow != fast){
        fast = fast->next;
        slow = slow->next;
    }

    // Step 3.3 they meet again at start node
    return slow;
}

// Function 3: Find the midpoint of the list
ListNode* midNode(ListNode* head){
    ListNode *fast = head, *slow = head;

    while(fast != head && fast->next != head){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

// Function 4: Find the last k-th node
ListNode* lastKNode(ListNode* head, int k){
    // Step 1. Initialise two pointers, both point to head
    ListNode *fast = head, *slow = head;

    // Step 2. Fast moves k nodes in advance
    while(fast != nullptr && k > 0){
        fast = fast->next;
        k--;
    }

    // Step 3. Traverse simultaneously
    while(fast != head){
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}

/*
 * Method 2.
 * LEFT AND RIGHT POINTERS
 * Is used to deal with array and string
 * */

// Function 1: Binary Search
// All binary search functions have left and right pointers

// Function 2: Two Sum
// Application of Binary Search
std::vector<int> twoSum(std::vector<int> nums, int target){
    // Step 1. Initialise Left and Right Pointers
    int left = 0, right = nums.size() - 1;

    // Step 2. Until [left, right] is empty
    while(left < right){
        // Step 2.1 Compute Sum of
        int sum = nums[left] + nums[right];

        // Step 2.2 Three Conditions
        if(sum == target) return std::vector<int>{left + 1, right + 1};
        else if(sum > target) right--; // Sum Decrease
        else if(sum < target) left++; // Sum Increase
    }

    // Step 3. No match found
    return std::vector<int>{-1, -1};
}

// Function 3: Reverse Array
void reverse(std::vector<int>nums){
    // Step 1. Initialise Left and Right Pointers
    int left = 0, right = nums.size() - 1;

    // Step 2. until [left, right] is empty
    while(left < right){
        // Step 2.1 Swap
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        // Step 2.2 Traverse
        left++; right--;
    }
}

/*
 * Method 3.
 * SLIDING WINDOW
 * Is used to deal with sub-string problem
 * */
// Function 1. 
