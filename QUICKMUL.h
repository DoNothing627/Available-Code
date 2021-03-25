typedef unsigned long long llu;
typedef long long lli;
llu Mul(llu x, llu y)
{
    x %= m; y %= m;
    llu q = (long double) x * y / m;
    lli r = lli(x * y - q * m) % (lli)m;
    if (r < 0) r += m;
    return r;
}