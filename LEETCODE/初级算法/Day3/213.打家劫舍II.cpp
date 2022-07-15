int ans1[105];
int ans2[105];//加了一个分割条件
int max(int a, int b)
{
    return a > b ? a : b;
}
int rob(int* nums, int numsSize){
//进阶课程
    int i, j;
    ans1[0] = nums[0];
    ans2[0] = 0;
    if (numsSize > 1)
    {
        ans2[1] = nums[1];
    }
    for (i = 1; i <= numsSize - 2; i++)
    {
        if (i - 2 >= 0)
        {
            ans1[i] = max(ans1[i - 2] + nums[i], ans1[i - 1]);
        }
        else
        {
            ans1[i] = max(ans1[i - 1], nums[i]);
        }
    }
    if (numsSize > 1)
    {
        ans1[numsSize - 1] = ans1[numsSize - 2];
    }
    for (i = 2; i <= numsSize - 1; i++)
    {
        if (i - 2 >= 0)
        {
            ans2[i] = max(ans2[i - 2] + nums[i], ans2[i - 1]);
        }
        else
        {
            ans2[i] = max(ans2[i - 1], nums[i]);
        }
    }
    return max(ans1[numsSize - 1], ans2[numsSize - 1]);
}
