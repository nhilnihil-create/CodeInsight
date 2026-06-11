#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

int main() {
    ll x,y;cin>>x>>y;
    ll ans = 0;
    ll xa = abs(x);
    ll ya = abs(y);
    
    ans += abs(ya - xa);
    
    if(x >= 0 && y >= 0 && x < y)ans+=0;
    else if(x > 0 && y > 0 && x > y)ans+=2;
    else if(x < 0 && y <= 0 && x < y)ans+=0;
    else if(x < 0 && y < 0 && x > y)ans+=2;
    else ans+=1;
    
    cout<<ans<<endl;
	return 0;
}