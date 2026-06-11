#include <bits/stdc++.h>
using namespace std;

int main(){
	long long N;
	cin >> N;
	vector<long long> a(N);
	vector<long long> ans(N,0);
	for(auto &i:a)cin >> i;
	
	vector<pair<long long,int>> v;
	for(int i=0;i<N;i++)v.push_back(make_pair(a[i],i));
	
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	
	set<int> s;
	for(int i=0;i<N;i++){
		s.insert(v[i].second);
		ans[*s.begin()]+=(long long)(i+1)*(v[i].first-((i<N-1)?(v[i+1].first):(0)));
	}
	
	for(auto i:ans)cout << i << endl;
	return 0;
}