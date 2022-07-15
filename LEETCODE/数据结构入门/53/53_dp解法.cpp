//分治算法强化
int maxSubArray(int* nums, int numsSize){
    int count, ans, i, flag = 0;
    ans = count = nums[0];
    for (i = 1; i <= numsSize - 1; i++)
    {
        if (flag == 0)
        {
            count = nums[i] > count + nums[i] ? nums[i] : count + nums[i];
        }
        ans = count > ans ? count : ans;
    }
    return ans;
}
