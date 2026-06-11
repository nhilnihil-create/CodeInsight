#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define rep(i, n) for(int i = 0; i < n; i++)
#define sort(v) sort((v).begin(), (v).end())
using vi = vector<int>;
using vs = vector<string>;
using vll = vector<ll>;
const int MOD = 1e9+7;
 
int main() {
	ll N,T;
  	cin >> N >> T;
  	vll t(N);
  	rep(i,N){
    	cin >> t[i];
    }
  	ll ans=T;
  	rep(i,N-1){
    	if(t[i+1] - t[i] >= T) ans += T;
      	else ans += t[i+1] - t[i];
    }
  	cout << ans << endl;
  
}