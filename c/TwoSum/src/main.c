#include "two-sum.h"
#include <stdlib.h>
#include <stdio.h>

void print_resul(int *ret, int *retSize, int *nums)
{
    printf("nums[%d] + nums[%d] = %d\n", ret[0], ret[1], nums[ret[0]] + nums[ret[1]]);
    printf("i=%d j=%d\n", ret[0], ret[1]);
    printf("retSize: %d\n", *retSize);
}
int main(int argc, char const *argv[])
{
    int nums[4] = {2, 7, 11, 15};
    int numSize = 4;
    int target = 9;
    int retSize;
    int *ret = two_sum_bruteforce(nums, numSize, target, &retSize);
    if (ret == NULL)
        return EXIT_FAILURE;
    print_resul(ret, &retSize, nums);
    free(ret);

    int *ret2 = two_sum_2_pointers(nums, numSize, target, &retSize);
    if (ret2 == NULL)
        return EXIT_FAILURE;
    print_resul(ret2, &retSize, nums);
    free(ret2);
    return 0;
}
