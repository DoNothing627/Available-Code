//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define oo 1000000007
#define PI 3.1415926535897
#define mn 1505
#define DoNothing "DELCHAR"
#define memset(f, a) memset(f, a, sizeof(f))
#define sz(a) int((a).size())
#define pb push_back
//#define int long long
#define ii pair< int, int>
//#define x first
//#define y second
using namespace std;

int n, m, w, f[mn][mn], res= 0, ans, t[4* mn][4* mn];
string a, b;

//deque< int> c[mn], d;

void up(int kx, int lx, int rx, int ky, int ly, int ry, int x, int y, int val)
{
    if(rx< x|| lx> x|| ry< y|| ly> y) return;
    //t[kx][ky]= max(t[kx][ky], val);
    if(lx== rx&& ly== ry){
        t[kx][ky]= max(t[kx][ky], val);
        return;
    }
    int mx= (lx+ rx)/ 2, my= (ly+ ry)/ 2;
    up(2* kx, lx, mx, 2* ky, ly, my, x, y, val);
    up(2* kx, lx, mx, 2* ky+ 1, my+ 1, ry, x, y, val);
    up(2* kx+ 1, mx+ 1, rx, 2* ky, ly, my, x, y, val);
    up(2* kx+ 1, mx+ 1, rx, 2* ky+ 1, my+ 1, ry, x, y, val);
    t[kx][ky]= max(t[2* kx][2* ky], max(t[2* kx][2* ky+ 1], max(t[2* kx+ 1][2* ky], t[2* kx+ 1][2* ky+ 1])));
}

void get(int kx, int lx, int rx, int ky, int ly, int ry, int u, int v, int x, int y)
{
    if(lx> x|| rx< u|| ly> y|| ry< v) return;
    //if(lx<= u&& rx>= x&& ly<= v&& ry>= y){
    if(u<=lx&&rx<=x&&v<=ly&&ry<=y){
		ans= max(ans, t[kx][ky]);
        return;
    }
    int mx= (lx+ rx)/ 2, my= (ly+ ry)/ 2;
    get(2* kx, lx, mx, 2* ky, ly, my, u, v, x, y);
    get(2* kx, lx, mx, 2* ky+ 1, my+ 1, ry, u, v, x, y);
    get(2* kx+ 1, mx+ 1, rx, 2* ky, ly, my, u, v, x, y);
    get(2* kx+ 1, mx+ 1, rx, 2* ky+ 1, my+ 1, ry, u, v, x, y);
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> w>> a>> b;
    w++;
    n= sz(a)+1, m= sz(b)+1;
    a= "  "+ a;
    b= "  "+ b;

    up(1,1,n,1,1,m,1,1,1);
    for(int i= 2; i<= n; i++)
        for(int j= 2; j<= m; j++)
    {
        if(a[i]!=b[j])continue;
        ans= 0;
        get(1, 1, n, 1, 1, m, max(i- w, 1), max(j- w, 1), i- 1, j- 1);
        if(ans==0)continue;
        ans++;
        up(1, 1, n, 1, 1, m, i, j,ans);
    }
    ans=0;
    get(1,1,n,1,1,m,max(n-w,1),max(m-w,1),n,m);
    cout<<ans-1;
    return 0;
}
