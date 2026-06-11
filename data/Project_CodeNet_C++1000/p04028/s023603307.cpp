#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const LL MOD = 1e9+7;

inline LL dmod(LL x){
	return x%MOD;
}

int n;
string s;
int pan;
LL memo[5005][5005];

LL dp(int id, int jadi){
	if(id >= n){
		if(jadi == pan) return 1LL;
		else return 0LL;
	}
	LL &ret = memo[id][jadi];
	if(ret!=-1) return ret;
	ret = 0LL;
	ret = dp(id+1,jadi+1)*2LL;
	ret = dmod(ret+dp(id+1,(jadi>0)?jadi-1:jadi));
	return ret;
}

LL fe(LL x, LL y){
	if(y==0) return 1LL;
	LL ret = fe(x,y/2);
	ret = dmod(ret*ret);
	if(y&1){
		ret = dmod(ret*x);
	}
	return ret;
}

int main(){
	memset(memo,-1,sizeof(memo));
	cin >> n;
	cin >> s;
	pan = s.size();
	LL ans = dp(0,0);
	LL tmp = fe(2LL,pan);
	ans = dmod(ans*fe(tmp,MOD-2));
	cout << ans << endl;
	return 0;
}