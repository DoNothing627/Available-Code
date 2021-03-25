//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "KBUILD"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, m, p[20][mn], f[mn], h[mn], BOSS[mn], topo[mn], dad[mn], c[mn], ans= 0, cnt= 0, res= 0;
vector< int> a[mn];

void dfs(int u)
{
    f[u]= 1;
    for(auto v: a[u])
    {
        if(p[0][u]== v) continue;
        p[0][v]= u;
        h[v]= h[u]+ 1;
        dfs(v);
        f[u]+= f[v];
    }
}

void rmq()
{
    forr(j, 1, 19)
        forr(i, 1, n)
            p[j][i]= p[j- 1][p[j- 1][i]];
}

int lca(int u, int v)
{
    if(h[u]< h[v]) swap(u, v);
    int del= h[u]- h[v];
    forr(i, 0, 19)
    if((del>> i)& 1) u= p[i][u];
    if(u== v) return u;
    for(int i= 19; i>= 0; i--)
    if(p[i][u]!= p[i][v]){
        u= p[i][u];
        v= p[i][v];
    }
    return p[0][u];
}

void hld(int u)
{
    if(!BOSS[cnt]) BOSS[cnt]= u;
    topo[u]= ++ans;
    dad[u]= cnt;
    int D= 0, NEED= 0;
    for(auto v: a[u])
    {
        //int v= a[u][i];
        if(v== p[0][u]) continue;
        if(f[v]> D){
            D= f[v];
            NEED= v;
        }
    }
    if(NEED) hld(NEED);
    for(auto v: a[u])
    {
        //int v= a[u][i];
        if(v== p[0][u]|| v== NEED) continue;
        ++cnt;
        hld(v);
    }
}

void up(int u, int w)
{
    int type= dad[u];
    while(type!= dad[w]){
        int v= BOSS[type];
        ++c[topo[v]];
        --c[topo[u]+ 1];
        u= p[0][v];
        type= dad[u];
    }
    ++c[topo[w]+ 1];
    --c[topo[u]+ 1];
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;
    forr(i, 1, n- 1)
    {
        int u, v;
        cin>> u>> v;
        a[u].pb(v), a[v].pb(u);
    }

    dfs(1), rmq();

    hld(1);
    cin>> m;
    forr(i, 1, m)
    {
        int u, v, w;
        cin>> u>> v;
        w= lca(u, v);
        up(u, w);
        up(v, w);
    }

    //cout<< n- 1- get(1, 1, n);
    forr(i, 2, n)
    {
        c[i]+= c[i- 1];
        if(!c[i]) ++res;
    }

    cout<< res;

    return 0;
}
