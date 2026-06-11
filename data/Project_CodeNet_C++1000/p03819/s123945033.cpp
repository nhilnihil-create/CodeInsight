#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define up(i,j,n)		for (int i = j; i <= n; i++)
#define down(i,j,n)	for (int i = j; i >= n; i--)
#define cmax(a,b)		a = max (a, b)
#define cmin(a,b)		a = min (a, b)
#define SZ(x)		(int)x.size()

const int MAXN = 3e5 + 5;
const int oo = 0x3f3f3f3f;

int N, M;
vector<int> S[MAXN];

namespace Seg{
	struct tree {
		int son[2], siz;
	}t[MAXN * 25];
	int root[MAXN], cnt = 0;
	int NewNode(int s0, int s1, int siz){
		cnt++;
		t[cnt].son[0] = s0; t[cnt].son[1] = s1;
		t[cnt].siz = siz;
		return cnt;
	}
	void Build(int le, int ri, int &k, int o){
		k = NewNode(t[k].son[0], t[k].son[1], t[k].siz + 1);
		if (le == ri) return;
		int mi = (le + ri) >> 1;
		if (o <= mi) 	Build(le, mi, t[k].son[0], o);
		else			Build(mi + 1, ri, t[k].son[1], o);
	}
	int Query(int le, int ri, int k, int L, int R){
		if (L <= le && ri <= R) return t[k].siz;
		int mi = (le + ri) >> 1, sum = 0;
		if (L <= mi) 		sum += Query(le, mi, t[k].son[0], L, R);
		if (mi + 1 <= R)		sum += Query(mi + 1, ri, t[k].son[1], L, R);
		return sum;
	}
}using namespace Seg;

namespace solution{
	void Prepare(){
		scanf("%d%d", &N, &M);
		up (i, 1, N) {
			int le, ri;
			scanf("%d%d", &le, &ri);
			S[ri].push_back(le);
		}
		down (i, M, 1) {
			root[i] = root[i + 1];	
			up (j, 0, SZ(S[i]) - 1) Build(1, M, root[i], S[i][j]);
		}
	}	
	void Solve(){
		up (i, 1, M) {
			ll ans = 0;
			for (int j = i; j <= M; j += i) ans += Query(1, M, root[j], j - i + 1, j);
			printf("%lld\n", ans);
		}
	}
}

int main(){
	using namespace solution;
	Prepare();
	Solve();
	return 0;
}
