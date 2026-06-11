# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
# define MOD 1000000007
														
using namespace std;
vector<int> a;
ll get(int tg){
	ll re=0;
	for (int v:a){
		ll tmp=v-tg;
		re+=tmp*tmp;
	}
	return re;
}

int main(){
	fastio;
	int n;
	cin>>n;
	a.assign(n,0);
	int mn=-100,mx=100;
	for (int &v:a){
		cin>>v;
		mn=min(mn,v);
		mx=max(mx,v);
	}
	ll ans=1e18;
	for (int i=mn;i<=mx;i++){
		ans=min(ans,get(i));
	}
	cout<<ans<<'\n';
	return 0;
}
	
