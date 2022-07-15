int stairs[1005];
int minCostClimbingStairs(int* cost, int costSize){
    int i;
    stairs[0] = 0;
    stairs[1] = 0;
    for (i = 2; i <= costSize; i++)
    {
        
        stairs[i]  = stairs[i - 1] + cost[i - 1] < stairs[i - 2] + cost[i - 2] ? stairs[i - 1] + cost[i - 1] : stairs[i - 2] + cost[i - 2];

    }
    return stairs[costSize];
}
