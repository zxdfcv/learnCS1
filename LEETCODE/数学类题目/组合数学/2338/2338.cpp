const int MOD = 1e9 + 7, MAX_VALUE = 1e4, MAX_K = 15;

int count[205][2], cntt = 0;
long long cmb[15000][25];
long long ans = 0;

void combination()
{
    int i, j;
    cmb[0][0] = cmb[1][0] = cmb[1][1] = 1;//可以巧妙处理
    for (i = 2; i <= MAX_VALUE + MAX_K - 1; i++)
    {
        cmb[i][0] = 1;
        for (j = 1; j <= MAX_K && j <= i; j++)
        {
            cmb[i][j] = (cmb[i - 1][j] + cmb[i - 1][j - 1]) % MOD;
        }
    }
}

void prime_count(int tar)
{
    int i, k = tar;
    if (k == 1)
    {
        return;
    }
    for (i = 2; i * i <= k; i++)
    {
        if (k % i == 0)
        {
            cntt++;
            count[cntt - 1][1] = 0;//初始化
            count[cntt - 1][0] = i;
            while (k % i == 0)
            {
                count[cntt - 1][1]++;
                k = k / i;
            }
        }
    }
    if (k > 1)
    {
        cntt++;
        count[cntt - 1][0] = k;
        count[cntt - 1][1] = 1;
    }
    if (cntt == 0)
    {
        cntt = 1;
        count[0][0] = tar;
        count[0][1] = 1;
    }
}
int idealArrays(int n, int maxValue){
    ans = cntt = 0;
    int i, j;
    long long anss = 1;
    memset(cmb, 0, sizeof(cmb));
    memset(count, 0, sizeof(count));
    combination();
    for (i = 1; i <= maxValue; i++)
    {
        cntt = 0;
        prime_count(i);
        anss = 1;
        for (j = 0; j <= cntt - 1; j++)
        {
            anss = (anss * cmb[n + count[j][1] - 1][count[j][1]]) % MOD;
        }
        /***
        if (cntt != 0)
        {
            anss = (anss * cmb[n][1]) % MOD;//非质因数1,本身也要计算在内
        }
        **/
        ans = (ans + anss) % MOD;
        printf("%lld ", ans);
    }
    puts("");
    for (i = 1; i <= 6; i++)
    {
        for (j = 0; j <= i; j++)
        {
            printf("%lld ", cmb[i][j]);
        }
        puts("");
    }
    
    return ans;
}//combinatorics 组合数学
