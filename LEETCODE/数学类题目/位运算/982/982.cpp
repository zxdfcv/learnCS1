int count[(1 << 16) + 1];//λ���������ȼ��ϵ�

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
            ans += count[j];//��Ӧ˫Ԫ��
        }
        ans += count[0];
    }
    return ans;
}
