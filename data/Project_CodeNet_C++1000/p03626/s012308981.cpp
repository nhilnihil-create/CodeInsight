// D - Coloring Dominoes
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rp(i,s,e) for(int i=(s);i<(e);++i)
#define MOD 1000000007

ll solve(int N, string &S1, string &S2){

	ll ans = 6;//ドミノが横のとき
	int start = 2;
	bool isPreVertical = false;//前回の状態: 縦: true, 横: false
	if(S1[0] == S2[0]){// 縦
		isPreVertical = true;
		ans = 3;
		start = 1;
	}

	rp(i, start, N){
		if(S1[i] == S2[i]){// 縦
			if(isPreVertical) ans = ans * 2 % MOD;
			else ans = ans * 1 % MOD;
			isPreVertical = true;
		}
		else{//横
			if(isPreVertical) ans = ans * 2 % MOD;
			else ans = ans * 3 % MOD;
			isPreVertical = false;
			i++;
		}
	}

	return ans;
}

int main(){
	int N; string S1,S2;
	cin>>N>>S1>>S2;
	cout<< solve(N, S1, S2) <<endl;
}