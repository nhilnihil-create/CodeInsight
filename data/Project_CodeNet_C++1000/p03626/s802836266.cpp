#include <bits/stdc++.h>
using namespace std;

long long MOD=1000000007ll;

int main(){
	int N;
	string S1,S2;
	cin >> N >> S1 >> S2;
	
	int pos=0;
	long long ans;
	bool v;
	if(S1[0]==S2[0]){
		ans=3;
		pos++;
		v=true;
	}else{
		ans=6;
		pos+=2;
		v=false;
	}
	
	for(;pos<N;){
		if(S1[pos]==S2[pos]){
			if(v)ans*=2;
			pos++;
			v=true;
		}else{
			if(v)ans*=2;
			else ans*=3;
			pos+=2;
			v=false;
		}
		if(ans>=MOD)ans%=MOD;
	}
	cout << ans << endl;
	return 0;
}