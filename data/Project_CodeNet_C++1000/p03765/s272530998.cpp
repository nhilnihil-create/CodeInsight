#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000

int main(){

	string S,T;
	cin>>S>>T;
	
	vector<int> SA(S.size()+1,0),SB(T.size()+1,0);
	
	for(int i=1;i<=S.size();i++){
		if(S[i-1] == 'A')SA[i] = 1;
		else SA[i]=2;
		SA[i]+=SA[i-1];
	}
	
	for(int i=1;i<=T.size();i++){
		if(T[i-1] == 'A')SB[i] = 1;
		else SB[i]=2;
		SB[i]+=SB[i-1];
	}
	
	int Q;
	cin>>Q;
	
	for(int i=0;i<Q;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		
		int X = SA[b] - SA[a-1];
		int Y = SB[d] - SB[c-1];
		
		X = abs(X-Y);
		
		if(X%3==0)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	return 0;
}