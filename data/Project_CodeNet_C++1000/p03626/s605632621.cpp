// D - Coloring Dominoes
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rp(i,s,e) for(int i=(s);i<(e);++i)
#define MOD 1000000007

ll solve(int N, string &S1, string &S2){
	bool isPreVertical;//前回の状態: 縦: true, 横: false
	ll ans = 0;
	rp(i, 0, N){
		ll mulnum = 1;
		if(S1[i] == S2[i]){// 縦
			if(i) mulnum = isPreVertical? 2:1;
			else ans = 3;//init
			isPreVertical = true;
		}
		else{//横
			if(i) mulnum = isPreVertical? 2:3;
			else ans = 6;//init
			isPreVertical = false;
			i++;
		}
		ans = ans * mulnum % MOD;
	}
	return ans;
}

int main(){
	int N; string S1,S2;
	cin>>N>>S1>>S2;
	cout<< solve(N, S1, S2) <<endl;
}