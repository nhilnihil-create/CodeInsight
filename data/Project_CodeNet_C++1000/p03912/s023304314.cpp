#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000

int main(){

	int N,M;
	cin>>N>>M;
	
	map<int,int> mp;
	for(int i=0;i<N;i++){
		int a;
		cin>>a;
		mp[a]++;
	}
	
	vector<int> num(M,0),Pnum(M,0);
	
	for(auto a:mp){
		Pnum[a.first%M] += a.second/2;
		num[a.first%M] += a.second;
	}
	
	int ans = 0;
	
	for(int i=0;i<=M/2;i++){
		if(i+i==M||i==0){
			ans += num[i]/2;
		}
		else{
			int x = min(num[i],num[M-i]);
			ans += x;
			num[i] -= x;
			num[M-i] -= x;
			
			ans += min(num[i]/2,Pnum[i]);
			ans += min(num[M-i]/2,Pnum[M-i]);
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}