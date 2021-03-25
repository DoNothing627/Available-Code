//--------CHICHARITO--------
#include <bits/stdc++.h>
#define LLC "NKPOS"
#define oo 1000000007
#define mn
#define pb push_back
#define ii pair< int, int>
using namespace std;

int n, m, a[210][210];
void euler()
{
    //vector< int> v;
    stack< int> S;
    S.push(1);
    cout<< m<< "\n";
    while(!S.empty())
    {
        int u= S.top(), ok= 0;
        //S.pop();
        for(int i= 1; i<= n; i++)
        {
            if(a[u][i]){
                S.push(i);
                ok= 1;
                a[u][i]--, a[i][u]--;
                break;
            }
        }
        if(!ok){
            S.pop();
            cout<< u<< " ";
        }
    }
    //cout<< m<< "\n";
    //for(int i= v.size()- 1; i>= 0; i--) cout<< v[i]<< " ";
    //cout<< v[v.size()- 1];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    //freopen(LLC".inp", "r", stdin);
    //freopen(LLC".out", "w", stdout);
    cin>> n>> m;
    int x;
    for(int i= 1; i<= n; i++) cin>> x;
    for(int i= 1; i<= m; i++)
    {
        int u, v;
        cin>> u>> v;
        a[u][v]++, a[v][u]++;
    }
    euler();
    return 0;
}
