#include <bits/stdc++.h>

using namespace std;

#define REP(i,n)	for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,s,n)	for(int i=(s), i##_len=(n); i<i##_len; ++i)

#define ALL(obj)	(obj).begin(),(obj).end()

typedef unsigned int 			uint;
typedef unsigned long long int	ull;
typedef long long int 			ll;

typedef pair<int,int>			P;

#define INF 		2000000007
#define MINF		-2000000007
#define MAX 		100005

const int MOD = 1e9+7;
// テンプレ終了
//====================================================================//


// agc071
int main(){
	int N;cin>>N;
	string s1,s2;cin>>s1>>s2;

	vector<int> p;
	REP(i,N){
		if(s1[i]==s2[i])
			p.push_back(0);
		else{
			p.push_back(1);
			i++;
		}
	}

	//for(int itr : p)cout << itr << " ";
	//cout << endl;

	ll ans = (p[0] ? 6 : 3);
	REPS(i,1,p.size()){
		if(p[i]==1){//横
			if(p[i-1]==1) ans = (ans * 3) %MOD;
			else ans = (ans * 2) %MOD;
		}else{// 縦
			if(p[i-1]==1)continue;
			else ans = (ans * 2) %MOD;
		}
	}

	cout << ans << endl;

	return 0;
}


