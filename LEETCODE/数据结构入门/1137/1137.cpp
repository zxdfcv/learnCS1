
int tribonacci(int n){
    int a = 0, b = 1, c = 1, tmp, i;
    for (i = 1; i <= n - 2; i++)
    {
        tmp = c;
        c = c + b + a;
        a = b;
        b = tmp;
    }
    if (n == 0)
    {
        return a;
    }
    else if (n == 1)
    {
        return b;
    }
    else
    {
        return c;
    }
}
