#include <bits/stdc++.h>
using namespace std;

#define pb(s) push_back(s)
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))

typedef long long ll;

ll f(ll a, ll b){
    ll ans=a/b;
    if(a%b) ans++;
    return ans;
}
int main()
{
std:
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    ll t1,a1;
    cin>>t1>>a1;
    n--;
    while(n--){
        ll x,y;
        cin>>x>>y;
        ll num=max(f(t1,x),f(a1,y));
        t1=num*x;
        a1=y*num;
    }
    cout<<t1+a1;

    return 0;
}
