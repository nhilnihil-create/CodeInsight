#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using ll = long long int;
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

int cnt[100100][3];

int main(void){
	int n,i,a,m,ans;
	std::cin >> n >> m;
	for(i=0; i<n; ++i){
		std::cin >> a;
		++cnt[a][0];
		++cnt[a%m][1];
	}
	for(i=1; i<=100000; ++i){
		cnt[i%m][2] += cnt[i][0]/2;
	}
	ans = cnt[0][1]/2;
	for(i=1; i<m; ++i){
		if(cnt[i][1]<cnt[m-i][1]){
			continue;
		}
		if(i==m-i){
			ans += cnt[i][1]/2;
			continue;
		}
		if(cnt[i][1]==cnt[m-i][1] && i>m-i){
			continue;
		}
		ans += cnt[m-i][1]+std::min((cnt[i][1]-cnt[m-i][1])/2,cnt[i][2]);
	}
	std::cout << ans << std::endl;
	return 0;
}
