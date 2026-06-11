#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue> 
#include <stack>
#include <set>
#include <list>

using namespace std;
typedef long long ll;
#define rep(i, s, e) for (int(i) = (s); (i) <= (e); ++(i))
#define all(x) x.begin(),x.end()


int main()
{
    ll n,a,b;cin>>n>>a>>b;
    ll now;cin>>now;
    ll ans = 0;
    rep(i,2,n){
        ll x;cin>>x;
        ans += min((x-now)*a, b);
        now = x;
    }
    cout<<ans<<endl;
}
