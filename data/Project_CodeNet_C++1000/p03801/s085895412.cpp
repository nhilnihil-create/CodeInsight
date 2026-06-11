#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<ll> a(N+1, 0), ans(N+1, 0), ninc;
	vector<int> inc{0};
	ll now=0;
	for(int i=1; i<=N; ++i){
	    cin >> a[i];
	    if(now<a[i]){
	        inc.push_back(i);
	        now=a[i];
	    }
	    else{
	        ninc.push_back(a[i]);
	    }
	}
	for(int i=1; i<inc.size(); ++i){
	    ans[inc[i]]=(a[inc[i]]-a[inc[i-1]])*(inc.size()-i);
	}
	sort(ninc.begin(), ninc.end());
	int ninc_now=0, inc_now=1;
	while(ninc_now<ninc.size()){
	    if(a[inc[inc_now]]<ninc[ninc_now]){
	        ans[inc[inc_now]] += (a[inc[inc_now]]-a[inc[inc_now-1]])*(ninc.size()-ninc_now);
	        ++inc_now;
	    }
	    else{
	        ans[inc[inc_now]] += ninc[ninc_now]-a[inc[inc_now-1]];
	        ++ninc_now;
	    }
	}
	for(int i=1; i<=N; ++i) cout << ans[i] << endl;
	return 0;
}
