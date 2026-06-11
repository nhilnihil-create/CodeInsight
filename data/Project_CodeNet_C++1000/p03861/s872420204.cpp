#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

ll countn(ll N,ll x){
    if(N >= 0)
        return N/x +1;
    else 
        return 0;
}

int main(void)
{
    ll a,b,x,ans;
    cin >> a >> b >> x;

    ans = countn(b,x)-countn(a-1,x);

    cout << ans << endl;
    
    return 0;
}