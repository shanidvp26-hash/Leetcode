int differenceOfSum(int* nums, int numsSize) {
    int element = 0;
    int digit = 0;
    for (int i = 0; i < numsSize; i++) {
        element += nums[i];
        int n = nums[i];
        while (n > 0) {
            digit += n % 10;
            n /= 10;
        }
    }
    return element > digit ? (element - digit) : (digit - element);
}
       