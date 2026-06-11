#include <iostream>
#include <bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define mid (L+R)/2
#define S second
#define F first
#define bi(x) x&-x
typedef long long ll;
using namespace std;
const int MAXN=1e5;
ll a[MAXN+10],b[MAXN+10];
ll abs1(ll x)
{
    return x<-1?-x:x;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    ll x,y;
    cin>>x>>y;
    if(abs1(x-y)>=2)
        printf("Alice\n");
    else
        printf("Brown\n");

}

