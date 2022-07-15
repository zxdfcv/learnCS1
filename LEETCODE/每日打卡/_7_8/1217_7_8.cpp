int minCostToMoveChips(int* position, int positionSize){
    int i, odd = 0, even = 0;
    for (i = 0; i <= positionSize - 1; i++)
    {
        if (position[i] % 2)
        {
            odd++;
        }
        else{
            even++;
        }
    }
    return odd < even ? odd : even;
}//ºËÐÄÊÇÆæÅ¼ÐÔ
