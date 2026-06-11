#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000

int main(){

	long long H,W;
	cin>>W>>H;
	
	vector<pair<long long,int>> V;
	
	for(int i=0;i<W;i++){
		long long P;
		cin>>P;
		V.emplace_back(P,0);
	}
	
	for(int i=0;i<H;i++){
		long long P;
		cin>>P;
		
		V.emplace_back(P,1);
	}
	
	sort(V.begin(),V.end());
	
	long long ans = 0;
	
	H++;
	W++;
	
	for(int i=0;i<V.size();i++){
		if(V[i].second == 0){
			ans += V[i].first * H;
			W--;
			if(W<0)W=0;
		}
		else{
			ans += V[i].first * W;
			H--;
			if(H<0)H=0;
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}