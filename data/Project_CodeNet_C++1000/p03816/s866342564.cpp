#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000


int main(){
	
	int N;
	cin>>N;
	
	map<int,int> mp;
	for(int i=0;i<N;i++){
		int a;
		cin>>a;
		mp[a]++;
	}
	
	int ans = mp.size();
	
	int k = 0;
	
	for(auto a:mp){
		k += a.second-1;
	}
	
	if(k%2==1){
		ans--;
	}
	
	cout<<ans<<endl;

	
	
    return 0;
}

