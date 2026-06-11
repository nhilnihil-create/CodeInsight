#pragma target("avx")
#include<bits/stdc++.h>
using ll = int_fast64_t;
using P = std::pair<ll,ll>;
using V = std::vector<ll>;
template<typename T> using pq = std::priority_queue<T>;
template<typename T> using rpq = std::priority_queue<T, std::vector<T>, std::greater<T>>;

#define rep(i,b,e) for(ll i=b; i<e; i++)
#define be(vec) vec.begin(),vec.end()
#define print(vec) printf("[ ");for(auto &i:vec)printf("%ld ",i);puts("]");
#define scan(vec) for(auto &i:vec)scanf("%ld",&i)
#define fi first
#define se second

const int MOD = 1e9+7;
const ll INF = 1e18;
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1}, dy[] = {1, 0, -1, 0, 1, -1, -1, 1};

int main(){
	char s[110], c;
	int l = 0;
	while((c=getchar()) != '\n') s[l++] = c;
	

	ll ans = 1e11;
	rep(x, 0, l){
		c = s[x];
		int cnt = 0;
		V a;
		rep(i, 0, l){
			if(s[i]!=c) cnt++;
			else{
				if(cnt) a.push_back(cnt);
				cnt = 0;
			}
		}
		if(cnt) a.push_back(cnt);
		
		ll tmp = 0;
		for(ll x: a) tmp = std::max(tmp, x);
		ans = std::min(ans, tmp);
	}
	printf("%ld\n", ans);
	return 0;
}
