#if !defined(TWO_SUM_H)
#define TWO_SUM_H
/**
 * Given an array of integers nums and an integer target, 
 * return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, 
 * and you may not use the same element twice.
 * You can return the answer in any order.
 * Example 1:
    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
    Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 * Example 2:
    Input: nums = [3,2,4], target = 6
    Output: [1,2]
 * Example 3:
    Input: nums = [3,3], target = 6
    Output: [0,1]
 */
extern int* two_sum_bruteforce(int* nums, int numsSize, int target, int* returnSize);



struct Element {
    unsigned short index;
    unsigned short value;
};



/**
 * The two pointers approach is simple. As precondition we need to:
 * 1. Create a data structure that holds value and index 
 * 2. Order the original array
 * 3. Cycle moving one of the two pointer
 * 4. check if the sum of left and right pointer is equal to target
 * 5. Otherwise move the pointer left++ (sum < target), right-- (sum > target)
 */
extern int* two_sum_2_pointers(int* nums, int numsSize, int target, int* returnSize);

#endif // TWO_SUM_H
