#include <cstdio>
#include <vector>
#include <algorithm>

#define PB push_back

using namespace std;

const int N = 2005;

vector < int > v[N];
int n, k;

int rezi(int x, int lst,int dis, int lim){
	int ret = (dis > lim);
	for(int y : v[x])
		if(y != lst)
			ret += rezi(y, x, dis + 1, lim);
	return ret;
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1;i < n;i++){
		int x, y; scanf("%d%d", &x, &y);
		v[x].PB(y), v[y].PB(x);
	}
	int sol = n;
	for(int i = 1;i <= n;i++){
		int ekstra = 0, sve = 0;
		for(int y : v[i]){
			sve += rezi(y, i, 1, k / 2);
			ekstra = max(ekstra, rezi(y, i, 1, k / 2) - rezi(y, i, 1, (k + 1) / 2));
		}
		sol = min(sol, sve - ekstra);
	}
	printf("%d\n", sol);
}