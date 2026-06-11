#include "bits/stdc++.h"
using namespace std;
typedef long long lint;
#define rep(i,n) for(int i=0;i<n;++i)
#define MAXN 100010
#define all(v) v.begin(),v.end()
#define inf 2147483647
#define linf 1152921504606846976

int main(){
	lint n;cin>>n;
	vector<pair<lint,lint> >a(n);
	rep(i,n){
		cin>>a[i].first;
		a[i].second=i;
	}sort(all(a),greater<pair<lint,lint> >());
	vector<lint>ans(n);lint mnpos=inf;
	rep(i,n-1){
		mnpos=min(mnpos,a[i].second);
		ans[mnpos]+=(a[i].first-a[i+1].first)*(i+1);
	}ans[0]+=a[n-1].first*n;
	rep(i,n)cout<<ans[i]<<endl;
}