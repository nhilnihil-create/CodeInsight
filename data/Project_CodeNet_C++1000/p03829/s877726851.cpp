#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main()
{
    ll n,a,b,i;
    ll ans = 0;
    cin >> n >> a >> b;
    vector<ll> x(n);
    for(i = 0;i < n;++i){
        cin >> x.at(i);
    }
    for(i = 1;i < n;++i){
        ans += min(a*(x.at(i)-x.at(i-1)),b);
    }
    cout << ans << endl;
    return 0;
}