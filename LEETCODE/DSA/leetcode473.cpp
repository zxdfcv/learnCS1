

int cnt[4], len;//����һ���Է���, ��Ȼ����
static bool dfs(int n, int matchsticksSize, int* matchsticks)
{
    int i;
    if (n == matchsticksSize)
    {
            return true;//һ������Χ��������
    }

    for (i = 0; i <= 3; i++)
    {
        if ((cnt[i] += matchsticks[n]) <= len && dfs(n + 1, matchsticksSize, matchsticks))
        {
            return true;
        }
        cnt[i] -= matchsticks[n];//����
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
        return 0;//����
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
    //�±���㿪ʼ
    return dfs(0, matchsticksSize, matchsticks);
}
