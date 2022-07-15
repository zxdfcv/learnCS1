
int dp[105][55][55];
int max(int i, int j, int k)
{
    int cnt = dp[i - 1][j][k];
    if (j > 0)
    {
        if (dp[i - 1][j - 1][k] > cnt)
        {
            cnt = dp[i - 1][j - 1][k];
        } 
    }
    if (k > 0)
    {
        if (dp[i - 1][j][k - 1] > cnt)
        {
            cnt = dp[i - 1][j][k - 1];
        } 
    }
    if (j > 0 && k > 0)
    {
        if (dp[i - 1][j - 1][k - 1] > cnt)
        {
            cnt = dp[i - 1][j - 1][k - 1];
        } 
    }
    return cnt;
}

int cherryPickup(int** grid, int gridSize, int* gridColSize){
    //????
    int i, j, k, l;
    memset(dp, 0x80, sizeof(dp));
    dp[0][0][0] = grid[0][0];
    /***
    for (i = 1; i <= gridSize - 1; i++)
    {
        if (grid[0][i] != -1)//x1 = x2 = 0
        {
            dp[i][0][0] = dp[i - 1][0][0] + grid[0][i];
            dp[i][1][0] = (dp[i - 1][0][0] > dp[i - 1][1][0] ? dp[i - 1][0][0] : dp[i - 1][1][0]) + grid[0][i];
            dp[i][0][1] = (dp[i - 1][0][0] > dp[i - 1][0][1] ? dp[i - 1][0][0] : dp[i - 1][0][1]) + grid[0][i];
        }
        if (grid[i][0] != -1)
        {
            dp[i][i][i] = dp[i - 1][i - 1][i - 1] + grid[i][0];
        }
    }
    ***/
    for (i = 1; i <= 2 * gridSize - 2; i++)
    {
        for (j = 0; j <= i && j <= gridSize - 1; j++)
        {
            if (i - j >= gridSize)
            {
                continue;
            }
            for (k = 0; k <= i && k <= gridSize - 1; k++)
            {
                if (i - k >= gridSize)
                {
                    continue;
                }
                if (grid[j][i - j] == -1 || grid[k][i - k] == -1)
                {
                    dp[i][j][k] = -2147483648;//INT_MIN
                }
                else
                {
                    if (j != k)
                    {
                        dp[i][j][k] = max(i, j, k);//????????//???????? ????
                        dp[i][j][k] = dp[i][j][k]+ grid[j][i - j] + grid[k][i - k]; 
                    }
                    else
                    {
                        dp[i][j][k] = max(i, j, k);
                        dp[i][j][k] = dp[i][j][k] + grid[j][i - j];
                    }//????
                }//????,????
            }
        }
    }
    return dp[2 * gridSize - 2][gridSize - 1][gridSize - 1] > 0 ? dp[2 * gridSize - 2][gridSize - 1][gridSize - 1] : 0;
}
