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
		ll mulnum;
		if(S1[i] == S2[i]){// 縦
			mulnum = isPreVertical? 2:1;
			isPreVertical = true;
		}
		else{//横
			mulnum = isPreVertical? 2:3;
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