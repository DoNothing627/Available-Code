int power(int a, int b)
{
    int c= 1;
    for(; b> 0; a= (a* a)% oo)
    {
        if(b% 2) c= (c* a)% oo;
        b/= 2;
    }
    return c;
}

void init()
{
    f[0]= 1;
    forr(i, 1, mn)
    f[i]= (f[i- 1]* i)% oo;
    forr(i, 0, mn)
    g[i]= power(f[i], oo- 2);
}

int C(int K, int N)
{
    int ans= (f[N]* g[K])% oo;
    ans= (ans* g[N- K])% oo;
    return ans;
}
