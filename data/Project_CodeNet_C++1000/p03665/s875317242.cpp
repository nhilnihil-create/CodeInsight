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
	int n, p;
	scanf("%d %d", &n, &p);
	ll one = 0, zero = 0;
	rep(i, 0, n){
		int tmp;
		scanf("%d", &tmp);
		if(tmp%2) one++;
		else zero++;
	}

	ll comb[one+1], sum=(p==0);
	comb[0] = 1;
	for(int i=1; i<=one; i++){
		comb[i] = comb[i-1] * (one-i+1) / i;
		if(i%2==p) sum += comb[i];
	}
	printf("%ld\n", sum * (1l<<zero));
	return 0;
}
