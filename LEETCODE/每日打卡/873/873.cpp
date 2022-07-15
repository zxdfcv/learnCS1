int cnt[1005][1005];//可以使用状态压缩
int ans[1005][2];//答案
int binSearch(int arr[], int tar, int l, int r)//复杂度O(n * n)logn 
{
    int mid = (r - l) / 2 + l;
    while (l <= r)
    { 
        if (arr[mid] > tar)
        {
            r = mid - 1;
        }
        else if(arr[mid] < tar)
        {
            l = mid + 1;
        }
        else
        {
            return mid;
        }
        mid = (r - l) / 2 + l;
    }
   return -1;
}
int lenLongestFibSubseq(int* arr, int arrSize){
    int i, j, k, flag, f1, f2, max = 0, buff;
    memset(cnt, 0, sizeof(cnt));
    if (arrSize <= 2)
    {
        return 0;
    }
    cnt[1][0] = 2;//初始条件//记录前一个数的下角标
    for (i = 0; i <= arrSize - 2; i++)
    {
        for (k = i + 1; k <= arrSize - 1; k++)
        {
            j = binSearch(arr, arr[k] - arr[i], 0, i - 1);
            if (j != -1)
            {
                 cnt[k][i] = (cnt[i][j] + 1) > 3 ? cnt[i][j] + 1 : 3;
            }
            else
            {
                cnt[k][i] = 0;
            }
        }
    }
    for (i = 0; i <= arrSize - 1; i++)
    {
        for (j = 0; j <= i - 1; j++)
        {
            max = cnt[i][j] > max ? cnt[i][j] : max;
        }
    }
    if (max >= 3)
    {
        return max;
    }
    else
    {
        return 0;
    }
}
