int count[(1 << 16) + 1];//位移运算优先级较低

int countTriplets(int* nums, int numsSize){
    int i, j, k, ans = 0, tar;
    memset(count, 0, sizeof(count));
    for (i = 0; i <= numsSize - 1; i++)
    {
        for (j = 0; j <= numsSize - 1; j++)
        {
            ++count[nums[i] & nums[j]];
        }
    }
    for (i = 0; i <= numsSize - 1; i++)
    {
        tar = (1 << 16) - 1 - nums[i];
        for (j = tar; j > 0; j = (j - 1)&tar)
        {
            ans += count[j];//对应双元组
        }
        ans += count[0];
    }
    return ans;
}
