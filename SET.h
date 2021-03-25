//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 100000000007
//#define int long long
#define DoNothing "CPPSET"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

set< int> s;
set< int> :: iterator c;
int type, u;

void lm(int type)
{
    if(type== 1)
        s.insert(u);
    if(type== 2&& s.find(u)!= s.end()) s.erase(u);
    if(type== 3){
        if(s.empty()) cout<< "empty"<< "\n";
        else{
            c= s.begin();
            cout<< *c<< "\n";
        }
    }
    if(type== 4){
        if(s.empty()) cout<< "empty"<< "\n";
        else{
            c= s.end();
            --c;
            cout<< *c<< "\n";
        }
    }
    if(type== 5){
        //if(s.empty()) cout<< "empty"<< "\n";
        c= s.upper_bound(u);
        if(c== s.end()) cout<< "no"<< "\n";
        else cout<< *c<< "\n";
    }
    if(type== 6){
        //if(s.empty()) cout<< "empty"<< "\n";
        c= s.lower_bound(u);
        if(c== s.end()) cout<< "no"<< "\n";
        else cout<< *c<< "\n";
    }
    if(type== 7){
        c= s.lower_bound(u);
        if(c== s.begin()) cout<< "no"<< "\n";
        else{
            --c;
            cout<< *c<< "\n";
        }
    }
    if(type== 8){
        c= s.upper_bound(u);
        if(c== s.begin()) cout<< "no"<< "\n";
        else{
            --c;
            cout<< *c<< "\n";
        }
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    //freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    while(cin>> type)
    {
        if(!type) break;
        //cin>> u;
        if(type!= 3&& type!= 4) cin>> u;
        lm(type);
    }


    return 0;
}
