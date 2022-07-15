

int cnt[4], len;//必须一次性返回, 不然不过
static bool dfs(int n, int matchsticksSize, int* matchsticks)
{
    int i;
    if (n == matchsticksSize)
    {
            return true;//一定可以围城正方形
    }

    for (i = 0; i <= 3; i++)
    {
        if ((cnt[i] += matchsticks[n]) <= len && dfs(n + 1, matchsticksSize, matchsticks))
        {
            return true;
        }
        cnt[i] -= matchsticks[n];//回溯
    }
    return false;
}

static int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}


bool makesquare(int* matchsticks, int matchsticksSize)
{
    int i;
    len = 0;
    for (i = 0; i <= 3; i++)
    {
        cnt[i] = 0;
    }
    qsort(matchsticks, matchsticksSize, sizeof(int), cmp);
    for (i = 0; i <= matchsticksSize - 1; i++)
    {
        len += matchsticks[i];
    }
    if (len % 4)
    {
        return 0;//特判
    }
    else
    {
        len /= 4;
    }
    for (i = 0; i <= matchsticksSize - 1; i++)
    {
        if (matchsticks[i] > len)
        {
            return 0;
        }
    }
    //下标从零开始
    return dfs(0, matchsticksSize, matchsticks);
}
