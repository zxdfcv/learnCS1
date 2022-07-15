int ans[105][2];
int max(int a, int b)
{
    return a > b ? a : b;
}
int rob(int* nums, int numsSize){
    int i;
    ans[0][1] = nums[0];
    ans[0][0] = 0;
    for (i = 1; i <= numsSize - 1; i++)
    {
        if (i > 1)
        {
            ans[i][0] = max(ans[i - 1][1], ans[i - 1][0]);
            ans[i][1] = max(ans[i - 1][0], max(ans[i - 2][0], ans[i - 2][1]) + nums[i]);
        }
        else
        {
            ans[i][0] = ans[i - 1][1];
            ans[i][1] = nums[i];
        }
    }//¶àÖØdp
    return max(ans[numsSize - 1][0], ans[numsSize - 1][1]);
}//
