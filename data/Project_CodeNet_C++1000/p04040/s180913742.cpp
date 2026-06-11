#include <bits/stdc++.h>
#define ll long long
using namespace std;

long long moduo=1000000007;
ll fak[200010];

ll stepen(ll a, ll st)
{
    if(st == 0) return 1;
    ll res = stepen(a, st/2);
    res %= moduo;
    res *= res;
    res %= moduo;
    if(st % 2 == 1)
    {
        res *= a;
        res %= moduo;
    }
    return res;
}
ll mul(ll a, ll b)
{
    a %= moduo;
    b %= moduo;
    return (a*b)%moduo;
}
 ll pref()
{
    fak[0] = 1;
    for(ll i = 1; i <= 200000; i++)
        fak[i] = mul(fak[i-1], i);
}
ll fakt(ll a)
{
    return fak[a];
}


long long res[100020];
long long r[100020];
int main()
{
    int h,w,a,b;
    cin>>h>>w>>a>>b;
    res[0]=1;
    pref();
    for(int k=1;k<=h-a;k++)
    {
        //res[k]=(res[k-1]*(k+b-1)*inverz(k,moduo-2))%moduo;
        res[k]=mul(res[k-1],k+b-1);
        res[k]=mul(res[k],stepen(k,moduo-2));
    }
    r[0] = fakt(h+w-b-2);
    r[0] %= moduo;
    r[0] = mul(r[0], stepen(fakt(w-b-1), moduo-2));
    r[0] = mul(r[0], stepen(fakt(h - 1), moduo-2));
    for(int k=1;k<=h-a;k++)
    {
        r[k]=mul(r[k-1],h-k+1-1);
        r[k]=mul(r[k],stepen(h-k+1+w-b-2,moduo-2));
    }

    long long rr=0;
    for(int k=0;k<h-a;k++)
       {
           rr+=mul(res[k],r[k]);
           rr%=moduo;
       }
    cout<<rr;
    return 0;
}
