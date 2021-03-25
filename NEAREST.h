//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define oo 1000000007
#define PI 3.1415926535897
#define mn 100005
#define DoNothing "NEAREST"
#define mem(f, a) memset(f, a, sizeof(f))
#define pb push_back
//#define int long long
#define ii pair< double, double>
#define x first
#define y second
using namespace std;

ii a[mn];
int n;
double res= oo;

double dist(int i, int j)
{
    return sqrt((a[i].x- a[j].x)* (a[i].x- a[j].x)+ (a[i].y- a[j].y)* (a[i].y- a[j].y));
}
struct cmp
{
    bool operator() (int i, int j) const
    {
        return a[i].y< a[j].y;
    }
};


set< int, cmp> s;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    //freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;
    for(int i= 1; i<= n; i++) cin>> a[i].x>> a[i].y;
    sort(a+ 1, a+ n+ 1);
    int id= 1;
    for(int i= 1; i<= n; i++)
    {
        while(a[i].x- a[id].x> res) s.erase(id++);
        a[0].y= a[i].y- res;
        set< int, cmp>:: iterator it= s.lower_bound(0);
        while(it!= s.end())
        {
            if(a[*it].y- a[i].y> res) break;
            res= min(res, dist(i, *it));
            it++;
        }
        s.insert(i);
    }
    cout<< fixed<< setprecision(3)<< res;
    return 0;
}
