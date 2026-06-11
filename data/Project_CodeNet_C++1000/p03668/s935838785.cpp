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

int dfs(int p , int q){
	int g = 0;
	for(auto u : V[q]){
		if(u == p) continue;
		g ^= dfs(q,u)+1;
	}
	return g;
}

int main(){
	cin >> N;
	repp(i,1,N){
		int x,y;
		cin >> x >> y;
		V[x].PB(y);
		V[y].PB(x);
	}
	cout << (dfs(-1,1)?"Alice":"Bob") << endl;
	return 0;
}
