#include <bits/stdc++.h>
#define rep(i,s,n) for(int i=s;i<n;i++)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
using P=pair<int,int>;
using G=vector<vector<int>>;
using ll=long long;




int main(){
	int n; cin>>n;
	ll a[n],b[n];
	vector<pair<ll,ll>> vec;
	rep(i,0,n) {
		ll ai,bi;
		cin>>ai>>bi;
		vec.push_back(make_pair(ai,bi));
	}

	sort(all(vec));
	ll l=vec.size();

	ll ans=vec[n-1].first + vec[n-1].second;
	cout << ans <<endl;


	
}
