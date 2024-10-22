#include "two-sum.h"

#include <stdlib.h>
#include <stdio.h>

int *two_sum_bruteforce(int *nums, int numsSize, int target, int *returnSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                *returnSize = 2;
                int *res = malloc(*returnSize * sizeof(int));
                res[0] = i;
                res[1] = j;
                return res;
            }
        }
    }
    return NULL;
}

#ifdef __APPLE__
// For macOS
#define QSORT_R(base, nmemb, size, compar, arg) \
    qsort_r(base, nmemb, size, arg, compar)
#else
// For Linux/BSD
#define QSORT_R(base, nmemb, size, compar, arg) \
    qsort_r(base, nmemb, size, compar, arg)
#endif

int compare_index(const void *a, const void *b, void *nums)
{
    return ((int *)nums)[(*(const int *)a)] - ((int *)nums)[(*(const int *)b)];
}

int *two_sum_2_pointers(int *nums, int numsSize, int target, int *returnSize)
{
    int left = 0;
    int right = numsSize - 1;

    int *res = malloc(2 * sizeof(int));
    if (res == NULL)
        return NULL;

    int *indices = malloc(numsSize * sizeof(int));
    if (indices == NULL)
    {
        free(res);
        return NULL;
    }

    for (int i = 0; i < numsSize; i++)
    {
        indices[i] = i;
    }

    qsort_r(indices, numsSize, sizeof(int), compare_index, nums);

    while (left < right)
    {
        if (nums[indices[left]] + nums[indices[right]] == target)
        {
            *returnSize = 2;
            res[0] = indices[left];
            res[1] = indices[right];
            free(indices);
            return res;
        }
        else if (nums[indices[left]] + nums[indices[right]] < target)
        {
            left += 1;
        }
        else
        {
            right -= 1;
        }
    }

    free(res);
    free(indices);

    return NULL;
}