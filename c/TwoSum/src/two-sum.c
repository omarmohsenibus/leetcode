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

int compare_element(const void *a, const void *b)
{
    struct Element *first = (struct Element *)a;
    struct Element *second = (struct Element *)b;

    return first->value - second->value;
}

int *two_sum_2_pointers(int *nums, int numsSize, int target, int *returnSize)
{
    unsigned short left = 0;
    unsigned short right = numsSize - 1;
    unsigned short sum = 0;

    struct Element *elements = malloc(numsSize * sizeof(struct Element));

    if (elements == NULL)
        return NULL;

    for (int i = 0; i < numsSize; i++)
    {
        elements[i].value = nums[i];
        elements[i].index = i;
    }
    qsort(elements, numsSize, sizeof(struct Element), compare_element);

    while (left < right)
    {
        sum = elements[left].value + elements[right].value;
        if (sum == target)
        {
            *returnSize = 2;
            int *res = malloc(*returnSize * sizeof(unsigned short));
            if(res == NULL) {
                free(elements);
                return NULL;
            }
                
            res[0] = elements[left].index;
            res[1] = elements[right].index;
            free(elements);
            return res;
        }
        else if (sum < target)
        {
            left += 1;
        }
        else
        {
            right -= 1;
        }
    }

    free(elements);

    return NULL;
}