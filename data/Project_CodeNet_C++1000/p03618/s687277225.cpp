#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000




int main(){
	string A;
	cin>>A;
	
	vector<long long> cnt(26,0);
	
	long long ans = 0;
	
	for(int i=0;i<A.size();i++){
		cnt[A[i]-'a']++;
	}
	
	for(int i=0;i<26;i++){
		ans += cnt[i] * (A.size()-cnt[i]);
	}
	
	ans /= 2;
	
	ans ++;
	
	cout<<ans<<endl;
	
	return 0;
}