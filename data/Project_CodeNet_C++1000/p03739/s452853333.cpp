#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

ll compute(vector<ll> &a){
	int n = a.size();
	ll sum = 0; ll ret = 0;
	for(int i = 0; i < n; i++){
		sum += a[i];
		if(i&1){
			if(sum >= 0){
				ret += sum + 1;
				sum = -1;
			}
		}else{
			if(sum <= 0){
				ret += abs(sum) + 1;
				sum = 1;
			}
		}
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n; cin>>n;
	vector<ll> a(n);
	for(auto &x : a){
		cin>>x;
	}
	ll ans = compute(a);
	for(auto &x : a){
		x = -x;
	}
	ans = min(ans, compute(a));
	cout<<ans<<endl;


	return 0;
}