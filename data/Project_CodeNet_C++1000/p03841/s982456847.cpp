#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, x[555], ans[255555];
    memset(ans, 0, sizeof(ans));
    
    cin >> n;
    rep(i, 1, n){
    	cin >> x[i];
    	ans[x[i]] = i;
    }
    
    vector<P> arg;
    rep(i, 1, n){
    	arg.push_back(P(x[i], i));
    }
    sort(arg.begin(), arg.end());
    
    queue<ll> q;
    zep(i, 0, n){
    	rep(j, 1, arg[i].second-1){
    		q.push(arg[i].second);
    	}
    }
    ll z = q.size();
    //printa(ans, 1, n*n)
    
    bool use[n+1]; memset(use, 0, sizeof(use));
    bool ok = true;
    rep(i, 1, n*n){
    	if(ans[i]){
    		use[ans[i]] = true;
    		rep(j, 1, n-ans[i]){
    			q.push(ans[i]);
    		}
    	}
    	else{
    		if(q.empty()){
    			ok = false;
    		}
    		else{
	    		ll x = q.front(); q.pop();
	    		z--;
	    		if(z > 0 && use[x]){
	    			ok = false;
	    		}
	    		ans[i] = x;
    		}
    	}
    }
    
    if(ok){
    	print("Yes")
    	printa(ans, 1, n*n)
    }
    else{
    	print("No")
    }
    return 0;
}