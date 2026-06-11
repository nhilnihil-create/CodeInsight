#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	ll c,k;
	cin >> n >> c >> k;
	vector<ll> t(n);
	rep(i,n) cin >> t[i];
	sort(t.begin(),t.end());
	ll bus = 1;
	ll time = 0;
	ll kazu = 0;
	ll s = t[0];
	int i = 0;
	while(i < n){
		if(t[i]-s>k||kazu>=c){
			bus++;
			s=t[i];
			kazu = 1;
			i++;
		}
		else{
			kazu++;
			i++;
		}
	}
	cout << bus << endl;
}