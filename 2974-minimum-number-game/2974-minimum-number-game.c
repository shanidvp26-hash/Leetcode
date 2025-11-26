#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int* numberGame(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* arr = (int*)malloc(sizeof(int) * numsSize);

    // Sort nums so we can remove the smallest elements easily
    qsort(nums, numsSize, sizeof(int), cmp);

    int idx = 0;

    // Process pairs (Alice removes min, Bob removes next min)
    for (int i = 0; i < numsSize; i += 2) {
        int alice = nums[i];       // smaller
        int bob   = nums[i + 1];   // next smaller

        // Bob appends first, then Alice
        arr[idx++] = bob;
        arr[idx++] = alice;
    }

    return arr;
}