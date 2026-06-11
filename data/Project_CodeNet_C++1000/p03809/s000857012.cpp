#include <cstdio>
#include <vector> 

#define PB push_back
#define X first
#define Y second

using namespace std;

typedef long long ll;

const int N = 1e5 + 500;

int n, A[N];
vector < int > v[N];
bool mogu = 1;

ll dfs(int x,int lst){
	if((int)v[x].size() == 1)	
		return A[x];
	ll sm = 0;
	for(int y : v[x]){
		if(y == lst) continue;
		ll dj = dfs(y, x);
		if(dj > A[x])
			mogu = 0;
		sm += dj;
	}
	if(sm < A[x] || sm > 2LL * A[x])
		mogu = 0;
	if(x == lst && sm != 2LL * A[x])
		mogu = 0;
	return 2LL * A[x] - sm;
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++)
		scanf("%d", A + i);
	if(n == 2){
		printf(A[1] == A[2] ? "YES\n" : "NO\n");
		return 0;
	}
	for(int i = 1;i < n;i++){
		int x, y; scanf("%d%d", &x, &y);	
		v[x].PB(y), v[y].PB(x);
	}
	for(int i = 1;i <= n;i++){
		if((int)v[i].size() > 1){
			dfs(i, i);
			break;
		}
	}
	printf(mogu ? "YES\n" : "NO\n");
	return 0;
}