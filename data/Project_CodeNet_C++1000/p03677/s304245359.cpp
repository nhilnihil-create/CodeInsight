#include <bits/stdc++.h>
using namespace std;
int a[100005];
vector<pair<int, int> > p;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N, M; cin>>N>>M;
	for(int i=0; i<N; ++i) cin>>a[i];
	for(int i=1; i<N; ++i){
		int s = a[i-1]%M+1, e = a[i];
		if(s<=e){
			p.emplace_back(s, -1);
			p.emplace_back(e, e-s+1);
			p.emplace_back(e+1, s-e);
		}
		else{
			p.emplace_back(1, -1);
			p.emplace_back(e, M-s+e+1);
			p.emplace_back(e+1, -M+s-e);
			p.emplace_back(s, -1);
		}
	}
	sort(p.begin(), p.end());
	long long x = 0;
	for(int i=1; i<N; ++i) x += min((a[i]+M-a[i-1])%M, 1+(a[i]-1)%M);
	long long ans = x, m = 0; 
	for(int i=1, j=0; i<M; ++i){
		while(j < p.size() && p[j].first <= i) m += p[j].second, ++j;
		x += m;
		ans = min(ans, x);
	}
	cout<<ans;
	return 0;
}