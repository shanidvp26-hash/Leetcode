int digitSum(int x) {
    int sum = 0;
    if (x < 0) x = -x;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int smallestIndex(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        if (digitSum(nums[i]) == i) {
            return i;
        }
    }
    return -1;
}
