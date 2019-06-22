/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// quick sort
static void _qsort(int *aSortedIdx, int *a, int size)
{
    int i;
    int piv_lo, piv_hi;

    if (!aSortedIdx || !a || size < 2)
        return;

    piv_hi = size - 1;
    piv_lo = piv_hi;
    for (i = piv_lo - 1; i >= 0; i--)
        if (a[aSortedIdx[i]] > a[aSortedIdx[piv_lo]]) {
            int temp = aSortedIdx[i];
            aSortedIdx[i] = aSortedIdx[piv_lo - 1];
            aSortedIdx[piv_lo - 1] = aSortedIdx[piv_hi];
            aSortedIdx[piv_hi] = temp;
            piv_lo--;
            piv_hi--;
        }
        else if (a[aSortedIdx[i]] == a[aSortedIdx[piv_lo]]) {
            int temp = aSortedIdx[i];
            piv_lo--;
            aSortedIdx[i] = aSortedIdx[piv_lo];
            aSortedIdx[piv_lo] = temp;
        }

    _qsort(aSortedIdx, a, piv_lo);
    _qsort(&aSortedIdx[piv_hi + 1], a, size - (piv_hi + 1));
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *numsSortedIdx;
    int i, j;

    numsSortedIdx = (int *)malloc(numsSize * sizeof(int));
    for (i = 0; i < numsSize; i++)
        numsSortedIdx[i] = i;
    _qsort(numsSortedIdx, nums, numsSize);

    i = 0;
    j = numsSize - 1;
    while (i < j) {
        if (nums[numsSortedIdx[i]] + nums[numsSortedIdx[j]] == target) {
            int *indices = (int *)malloc(2 * sizeof(int));
            indices[0] = numsSortedIdx[i];
            indices[1] = numsSortedIdx[j];
            *returnSize = 2;
            return indices;
        }
        else if (nums[numsSortedIdx[i]] + nums[numsSortedIdx[j]] < target) {
            ++i;
        }
        else {
            // nums[numsSortedIdx[i]] + nums[numsSortedIdx[j]] > target
            --j;
        }
    }
    *returnSize = 0;
    return NULL;
}
