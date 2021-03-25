#include <bits/stdc++.h>
#define forr(i, a, b) for(long i= a; i<= b; i++)
#define mn 1001
using namespace std;
int n, m, q, res= 0, lit[mn], match[mn];
bool av[mn], found, ok= true;
vector< int> a[mn];

void dfs(int u)
{
    for(auto v: a[u])
    {
        if(av[v]) continue;
        av[v]= 1;
        if(!match[v]) found= 1;
        else dfs(match[v]);
        if(found== 1){
            match[v]= u;
            return;
        }
    }
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    //freopen("nkbm.inp", "r", stdin);
    //freopen("nkbm.out", "w", stdout);
    cin>> n>> m>> q;
    forr(i, 1, q)
    {
        long u, v;
        cin>> u>> v;
        a[u].push_back(v);
    }
    long nlist= n;
    forr(i, 1, n) lit[i]= i;
    while(ok){
        ok= false;
        memset(av, 0);
        forr(i, 1, nlist)
        {
            found= 0;
            dfs(lit[i]);
            if(found== 1){
                lit[i]= lit[nlist];
                nlist--;
                ok= true;
            }
        }
    }
    forr(i, 1, m) if(match[i]) ++res;
    cout<< res;
}
