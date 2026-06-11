#include <iostream>
#include <iomanip>
#include <vector>
typedef long long ll;
using namespace std;
const  ll INF = 1e9;
const  ll MOD = 1e9 + 7;
#define repi(i,n,init) for(ll i=init;i<(n);i++)

int main()
{
    ll n,m;
    cin >> n >> m;
    vector<ll> G(n,0);
    repi(i,m,0){
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        G[a]++;
        G[b]--;
    }
    repi(i,n,1){
        G[i] += G[i-1];
    }
    repi(i,n-1,0){
        if(G[i]%2){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}