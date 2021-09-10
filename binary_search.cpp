#include <iostream>
#include <vector>

// Function 1. Binary Search to find the target
int binarySearchNum(std::vector<int> nums, int target){
    // Step 1. Define Left and Right: [left, right]
    int left = 0, right = nums.size() - 1;

    // Step 2. Search until [left, right] is Empty
    while(left <= right){
        // Step 2.1. Define mid, use (right - left) to avoid integer overflow
        int mid = left + (right - left) / 2;

        // Step 2.2. Shrink Range due to result of comparison
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) left = mid + 1;
        else if(nums[mid] > target) right = mid - 1;
    }

    // Step 3. If target is not found
    return -1;
}

// Function 2. Binary Search to find left bound of the target
int binarySearchLeft(std::vector<int> nums, int target){
    // Step 1. Define Left and Right: [left, right)
    int left = 0, right = nums.size();

    // Step 2. Search until [left, right) is Empty
    while(left < right){
        // Step 2.1. Define mid, use (right - left) to avoid integer overflow
        int mid = left + (right - left) / 2;

        // Step 2.2. Shrink Range due to result of comparison
        if(nums[mid] == target) right =  mid;
        else if(nums[mid] < target) left = mid + 1;
        else if(nums[mid] > target) right = mid;
    }

    // Step 3. If target is not found
    if(left >= nums.size() || nums[left] != target) return -1;

    // Step 4. Target is found
    else return left;
}

// Function 3. Binary Search to find left bound of the target
int binarySearchLeftSec(std::vector<int> nums, int target){
    // Step 1. Define Left and Right: [left, right]
    int left = 0, right = nums.size() - 1;

    // Step 2. Search until [left, right] is Empty
    while(left <= right){
        // Step 2.1. Define mid, use (right - left) to avoid integer overflow
        int mid = left + (right - left) / 2;

        // Step 2.2. Shrink Range due to result of comparison
        if(nums[mid] == target) right =  mid - 1;
        else if(nums[mid] < target) left = mid + 1;
        else if(nums[mid] > target) right = mid - 1;
    }

    // Step 3. If target is not found
    if(left >= nums.size() || nums[left] != target) return -1;

    // Step 4. Target is found
    else return left;
}

// Function 4. Binary Search to find left bound of the target
int binarySearchRight(std::vector<int> nums, int target){
    // Step 1. Define Left and Right: [left, right)
    int left = 0, right = nums.size();

    // Step 2. Search until [left, right) is Empty
    while(left < right){
        // Step 2.1. Define mid, use (right - left) to avoid integer overflow
        int mid = left + (right - left) / 2;

        // Step 2.2. Shrink Range due to result of comparison
        if(nums[mid] == target) left =  mid + 1;
        else if(nums[mid] < target) left = mid + 1;
        else if(nums[mid] > target) right = mid;
    }

    // Step 3. If target is not found
    if(left == 0 || nums[left - 1] != target) return -1;

    // Step 4. Target is found
    // At this time, left == right, so right - 1 = left - 1 = mid
    else return right - 1;
}

// Function 5. Binary Search to find left bound of the target
int binarySearchRightSec(std::vector<int> nums, int target){
    // Step 1. Define Left and Right: [left, right]
    int left = 0, right = nums.size() - 1;

    // Step 2. Search until [left, right] is Empty
    while(left <= right){
        // Step 2.1. Define mid, use (right - left) to avoid integer overflow
        int mid = left + (right - left) / 2;

        // Step 2.2. Shrink Range due to result of comparison
        if(nums[mid] == target) left =  mid + 1;
        else if(nums[mid] < target) left = mid + 1;
        else if(nums[mid] > target) right = mid - 1;
    }

    // Step 3. If target is not found
    if(left == 0 || nums[left - 1] != target) return -1;

    // Step 4. Target is found
    // At this time, left == right - 1, so right = left + 1 = mid
    else return right;
}

int main() {
    // Test case
    std::vector<int> nums{1, 2, 2, 3, 3, 3, 4, 5, 7, 9, 10, 11, 11, 11, 14, 21, 22, 22, 22, 22, 27, 38, 42, 42, 76, 79, 79, 79, 79, 79, 108, 110};
    int result;

    // Print Test Vector
    std::cout << "The test vector, nums is [";
    for(auto iter : nums){
        std::cout << iter << ", ";
    }
    std::cout << "]." << std::endl;

    // Function 1. Binary Search to find the target
    result = binarySearchNum(nums, 22);
    std::cout << "Function 1, The index of target 22 is " << result
              << ", meanwhile the value of nums[" << result << "] is " << nums[result] << std::endl;

    // Function 2. Binary Search to find left bound of the target
    result = binarySearchLeft(nums, 79);
    std::cout << "Function 2, The left bound of target 79 is " << result
              << ", meanwhile the value of nums[" << result << "] is " << nums[result] << std::endl;

    // Function 3. Binary Search to find left bound of the target
    result = binarySearchLeftSec(nums, 3);
    std::cout << "Function 3, The search result of target 3 is " << result
              << ", meanwhile the value of nums[" << result << "] is " << nums[result] << std::endl;

    // Function 4. Binary Search to find right bound of the target
    result = binarySearchRight(nums, 11);
    std::cout << "Function 4, The search result of target 11 is " << result
              << ", meanwhile the value of nums[" << result << "] is " << nums[result] << std::endl;

    // Function 5. Binary Search to find a number
    result = binarySearchRightSec(nums, 42);
    std::cout << "Function 5, The search result of target 42 is " << result
              << ", meanwhile the value of nums[" << result << "] is " << nums[result] << std::endl;

    return 0;
}
