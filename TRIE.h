#include <bits/stdc++.h>

using namespace std;
const long N=2e5+5;
string a[N];
long n;
struct trie
{
    trie *c[26];
    trie *cha;
    stack<long>id;
    trie()
    {
        memset(c,0,sizeof(c));
    }
};
trie T;
void nhap()
{
    cin>>n;
    for(long i=1;i<=2*n;++i)
        cin>>a[i];
}
void add(string s,long x)
{
    long k,id=0;
    trie *p=&T;
    for(long i=0;i<s.size();++i)
    {
        k=s[i]-'a';
        if(p->c[k]==nullptr)
            p->c[k]=new trie();
        p->c[k]->cha=p;
        p=p->c[k];
    }
    p->id.push(x);
}
bool sx(string A,string B)
{
    return A.size()>B.size();
}
void kkk(string s)
{
    long k,id,pos;
    trie *p=&T;
    for(long i=0;i<s.size();++i)
    {
        k=s[i]-'a';
        p=p->c[k];
    }
    if(p->id.size()==0)return;
    id=p->id.top();
    p->id.pop();
    for(long i=0;i<s.size();++i)
    {
        if(p->id.size())
        {
            pos=p->id.top();
            p->id.pop();
            cout<<pos<<" "<<id<<"\n";
            return;
        }
        p=p->cha;
    }
}
void lam()
{
    for(long i=1;i<=2*n;++i)
        add(a[i],i);
    sort(a+1,a+2*n+1,sx);
    for(long i=1;i<=2*n;++i)
        kkk(a[i]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("account.inp","r",stdin);
    freopen("account.out","w",stdout);
    nhap();
    lam();
    return 0;
}
