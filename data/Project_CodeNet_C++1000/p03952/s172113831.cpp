#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000


int main(){
	
	int N,x;
	cin>>N>>x;
	
	N=2*N-1;
	
	vector<int> A(N);
	
	for(int i=0;i<N;i++){
		A[i]=i+1;
	}
	
	if(x==N||x==1){
		cout<<"No"<<endl;
		return 0;
	}
	
	vector<int> ans(N,-1);
	
	int l = N/2;
	int r = N/2;
	set<int> S;
	int cnt = 0;
	
	while(true){
		if(l<0)break;
		if(r>=N)break;
		if(x-cnt<=0)break;
		if(x+cnt>N)break;
		ans[l] = x-cnt;
		ans[r] = x+cnt;
		S.insert(x-cnt);
		S.insert(x+cnt);
		l--;r++;
		cnt++;
	}
	
	int k = 1;
	
	for(int i=0;i<N;i++){
		if(ans[i]!=-1)continue;
		while(S.count(k)){
			k++;
		}
		S.insert(k);
		ans[i]=k;
	}
	cout<<"Yes"<<endl;
	for(int i=0;i<N;i++){
		cout<<ans[i]<<endl;
	}
	
	return 0;
}
