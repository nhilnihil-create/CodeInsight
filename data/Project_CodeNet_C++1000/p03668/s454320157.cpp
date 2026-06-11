#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int , int> P2;
typedef pair<pair<int , int> , int> P3;
typedef pair<pair<int , int> , pair<int , int> > P4;
#define PB(a) push_back(a)
#define MP(a , b) make_pair((a) , (b))
#define M3P(a , b , c) make_pair(make_pair((a) , (b)) , (c))
#define M4P(a , b , c , d) make_pair(make_pair((a) , (b)) , make_pair((c) , (d)))
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)

const int MC = 100010;
int N;
vector<int> V[MC];
int G[MC];

int dfs(int p , int q){
	int z = 0;
	for(auto u : V[q]){
		if(u == p) continue;
		z ^= dfs(q,u) + 1;
	}
	return z;
}

int main(){
	scanf("%d" , &N);
	repp(i,1,N){
		int x,y;
		scanf("%d%d" , &x , &y);
		V[x].PB(y);
		V[y].PB(x);
	}
	printf("%s\n" , dfs(-1,1) == 0 ? "Bob" : "Alice");
	return 0;
}
