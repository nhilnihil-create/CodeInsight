#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000

int main(){

	int N;
	cin>>N;
	
	vector<pair<long long,int>> P(N);
	
	for(int i=0;i<N;i++){
		cin>>P[i].first;
		P[i].second = i;
	}
	
	sort(P.rbegin(),P.rend());
	P.push_back({0,0});
	
	vector<long long> ans(N,0);
	
	for(int i=0;i<N;i++){
		if(i!=0)P[i].second = min(P[i].second,P[i-1].second);
		ans[P[i].second] += (P[i].first - P[i+1].first) * (i+1);
	}
	
	for(int i=0;i<N;i++){
		cout<<ans[i]<<endl;
	}
	
	return 0;
}