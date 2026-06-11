#include<stdio.h>
#include<map>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MM = 1000000007;
const int MX = 100005;

vector<int> T[MX];
int cnt[MX];
int N, K;

pii dfs(int x){
	pii r = pii(0, 0);
	for(int c : T[x]){
		pii t = dfs(c);
		if( t.second == K-1 && x != 1 ) t.second = 0, t.first++;
		else t.second++;
		r.first += t.first;
		r.second = max(r.second, t.second);
	}
	return r;
}

int main()
{
	scanf("%d%d", &N, &K);
	int ans = 0;
	for(int i = 1; i <= N; i++){
		int a;
		scanf("%d", &a);
		if( i == 1 ){
			if( a != 1 ) ans++;
		}
		else{
			T[a].push_back(i);
		}
	}
	ans += dfs(1).first;
	printf("%d\n", ans);
}
