//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define oo 1000000007
#define PI 3.1415926535897
#define mn 100002
#define DoNothing "SEGSQRSS"
#define mem(f, a) memset(f, a, sizeof(f))
#define pb push_back
#define int long long
#define ii pair< long, long>
#define sqr first
#define sum second
using namespace std;

int t, n, q, ladd[4* mn], lset[4* mn], a[mn];
ii it[4* mn];

void init(int k, int l, int r)
{
    if(l== r){
        it[k].sqr= a[l]* a[l];
        it[k].sum= a[l];
        return;
    }
    int mid= (l+ r)/ 2;
    init(2* k, l, mid);
    init(2* k+ 1, mid+ 1, r);
    it[k].sqr= it[2* k].sqr+ it[2* k+ 1].sqr;
    it[k].sum= it[2* k].sum+ it[2* k+ 1].sum;
}

void upadd(int k, int l, int r, int u, int v, int val)
{
    if(l> v|| r< u) return;
    if(l>= u&& r<= v){
        it[k].sqr+= val* val* (r- l+ 1)+ 2* val* it[k].sum;
        it[k].sum+= val* (r- l+ 1);
        ladd[k]+= val;
        return;
    }
    int mid= (l+ r)/ 2;
    if(ladd[k]){
        upadd(2* k, l, mid, l, r, ladd[k]);
        upadd(2* k+ 1, mid+ 1, r, l, r, ladd[k]);
        ladd[k]= 0;
    }
    upadd(2* k, l, mid, u, v, val);
    upadd(2* k+ 1, mid+ 1, r, u, v, val);
    it[k].sum= it[2* k].sum+ it[2* k+ 1].sum;
    it[k].sqr= it[2* k].sqr+ it[2* k+ 1].sqr;
}

void upset(int k, int l, int r, int u, int v, int val)
{
    if(l> v|| r< u) return;
    if(l>= u&& r<= v){
        it[k].sqr= val* val* (r- l+ 1);
        it[k].sum= val* (r- l+ 1);
        lset[k]= val;
        return;
    }
    int mid= (l+ r)/ 2;
    if(lset[k]){
        upset(2* k, l, mid, l, r, lset[k]);
        upset(2* k+ 1, mid+ 1, r, l, r, lset[k]);
        lset[k]= 0;
    }
    upset(2* k, l, mid, u, v, val);
    upset(2* k+ 1, mid+ 1, r, u, v, val);
    it[k].sum= it[2* k].sum+ it[2* k+ 1].sum;
    it[k].sqr= it[2* k].sqr+ it[2* k+ 1].sqr;
}

int get(int k, int l, int r, int u, int v)
{
    if(l> v|| r< u) return 0;
    if(l>= u&& r<= v)
        return it[k].sqr;
    int mid= (l+ r)/ 2;
    if(lset[k]){
        upset(2* k, l, mid, l, r, lset[k]);
        upset(2* k+ 1, mid+ 1, r, l, r, lset[k]);
        lset[k]= 0;
    }
    if(ladd[k]){
        upadd(2* k, l, mid, l, r, ladd[k]);
        upadd(2* k+ 1, mid+ 1, r, l, r, ladd[k]);
        ladd[k]= 0;
    }
    return get(2* k, l, mid, u, v)+ get(2* k+ 1, mid+ 1, r, u, v);
}

void RESET()
{
    mem(ladd, 0), mem(lset, 0);
    mem(it, 0);
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    //freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> t;
    for(int c= 1; c<= t; c++)
    {
        RESET();
        cin>> n>> q;
        for(int i= 1; i<= n; i++)
            cin>> a[i];
        init(1, 1, n);
        cout<< "Case "<< c<< ":"<< "\n";
        while(q--){
            int type, l, r, val;
            cin>> type;
            if(type== 2){
                cin>> l>> r;
                cout<< get(1, 1, n, l, r)<< "\n";
            }
            if(type== 1){
                cin>> l>> r>> val;
                upadd(1, 1, n, l, r, val);
            }
            if(!type){
                cin>> l>> r>> val;
                upset(1, 1, n, l, r, val);
            }
        }
    }
    return 0;
}
