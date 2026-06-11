#include<bits/stdc++.h>
using namespace std;
 
 
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	long long k;
	cin>>n>>k;
	vector<pair<int,int> > v;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		v.push_back({x,y});
	}
	sort(v.begin(),v.end());
	
	long long cnt = 0;
	int i = 0;
	while(cnt < k && i < n){
		cnt += v[i].second;
		i++;
	}
	i--;
	cout<<v[i].first;
	
	return 0;
}
