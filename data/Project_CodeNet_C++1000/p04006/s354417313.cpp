#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000000000000



int main(){
	
	int N;
	long long x;
	cin>>N>>x;
	vector<long long> a(N);
	for(int i=0;i<N;i++){
		cin>>a[i];
	}
	
	vector<vector<long long>> mini(N,vector<long long>(N,Inf));//mini[i][j] i番目要素から直前j個数のmin
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(j==0){
				mini[i][j] = a[i];
				continue;
			}
			else{
				int k = i-j;
				if(k<0)k+=N;
				mini[i][j] = min(mini[i][j-1],a[k]);
			}
		}
	}
	
	long long ans = Inf;
	
	for(int i=0;i<N;i++){
		long long temp = i*x;
		for(int j=0;j<N;j++){
			temp += mini[j][i];
		}
		ans = min(ans,temp);
	}
	
	cout<<ans<<endl;
	
	return 0;
}
