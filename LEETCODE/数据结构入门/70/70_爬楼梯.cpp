int climbStairs(int n){
    //ѧ���ø߾���ģ��
    int a = 1, b = 2, i;
    for (i = 1; i <= n - 2; i++)
    {
        b = a + b;
        a = b - a;
    }
    if (n == 1)
    {
        return 1;
    }
    else 
    {
        return b;
    }
}
