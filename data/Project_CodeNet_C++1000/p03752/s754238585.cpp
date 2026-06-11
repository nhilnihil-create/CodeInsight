#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int N,K;
	cin >> N >> K;
	vector<ll> a;
	for(int i=0; i<N; i++){int tt; cin >> tt; a.push_back(tt); }

	ll ans = 1e18;
	for(int bit=0; bit<(1<<N); bit++){
		vector<int> cp(N);
		copy(a.begin(),a.end(),cp.begin());
		int t = cp[0]; ll diff=0;
		for(int i=1; i<N; i++){
			if(bit & (1<<i)){
				if(t>=cp[i]){diff += t-cp[i]+1; cp[i]+=t-cp[i]+1;}

			}
			 t = max(t,cp[i]);
		}
		int cnt=0;
		t = cp[0];
		for(int i=1; i<N; i++){
			if(cp[i]>t){cnt++; t=cp[i];}
		}
		if(cnt>=K-1){ ans = min(ans,diff); }
	}

	cout << ans << endl;
}