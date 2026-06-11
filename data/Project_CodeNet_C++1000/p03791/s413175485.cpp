//satyaki3794
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define MOD (1000000007LL)
#define LEFT(n) (2*(n))
#define RIGHT(n) (2*(n)+1)

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

ll pwr(ll base, ll p, ll mod = MOD){
ll ans = 1;while(p){if(p&1)ans=(ans*base)%mod;base=(base*base)%mod;p/=2;}return ans;
}



ll fac[100005];


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fac[0] = 1;
    for(int i=1;i<=100000;i++)
    	fac[i] = (i * fac[i-1]) % MOD;

    int n;
    cin>>n;

    vector<int> arr;
    ll ans = 1;
    while(n--){
    	int x;
    	cin>>x;
    	if(x < 2*((int)arr.size()+1)-1)
    		ans = (ans * ((int)arr.size()+1)) % MOD;
    	else
    		arr.pb(x);
    }

    ans *= fac[(int)arr.size()];
    ans %= MOD;
    cout<<ans;
    return 0;
}


