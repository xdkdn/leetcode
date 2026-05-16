#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int minSubArrayLen(int target, int* nums, int numsSize) 
{
    int left = 0;
    int sum = 0;
    int minLen = INT_MAX;
    for (int right = 0; right < numsSize; right++) {
        sum += nums[right];
        while (sum >= target) 
		{
            int currentLen = right - left + 1;
            if (currentLen < minLen) {
                minLen = currentLen;
            }
            sum -= nums[left];
            left++;
        }
    }
    return minLen == INT_MAX ? 0 : minLen;
}
int main(){
    int target;
    int n;
    scanf("%d", &target);
    scanf("%d", &n);
    int* nums = (int*)malloc(n * sizeof(int));
    if (nums == NULL) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    int result = minSubArrayLen(target, nums, n);
    printf("%d\n", result);
    free(nums);
    return 0;
}