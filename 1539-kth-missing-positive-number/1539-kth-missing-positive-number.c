int findKthPositive(int* arr, int arrSize, int k) {
    int current = 1;
    int index = 0;   
    while (k > 0) {
        if (index >= arrSize || arr[index] != current) {
            k--;
            if (k == 0)
                return current;
        } else {
            index++;
        }
        current++;
    }
    return current;
}
