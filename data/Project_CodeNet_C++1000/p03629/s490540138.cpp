#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF = (1<<30);
const ll INFLL = (1ll<<60);
const ll MOD = (ll)(1e9+7);

#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	a = (a<MOD)?a:(a-MOD);
	b = (b<MOD)?b:(b-MOD);
	a += b;
	a = (a<MOD)?a:(a-MOD);
}

int d[225816][26],memo[225816];
bool done[225816];

int solve(int i){
	int j;
	if(i==INF){
		return 0;
	}
	if(done[i]){
		return memo[i];
	}
	done[i] = true;
	memo[i] = INF;
	for(j=0; j<26; ++j){
		memo[i] = min(memo[i],solve(d[i][j])+1);
	}
	return memo[i];
}

int main(void){
	int n,i,j;
	string s;
	cin >> s;
	n = s.l_ength();
	for(j=0; j<26; ++j){
		d[n][j] = INF;
		for(i=n-1; i>=0; --i){
			d[i][j] = d[i+1][j];
			if(s[i] == 'a'+j){
				d[i][j] = i+1;
			}
		}
	}
	i = 0;
	while(i<INF){
		for(j=0; j<26; ++j){
			if(solve(i) == solve(d[i][j])+1){
				cout << ((char)('a'+j));
				i = d[i][j];
				break;
			}
		}
	}
	cout << endl;
	return 0;
}
