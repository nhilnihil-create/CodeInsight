#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

struct BIT{
	vector<int> val;
	BIT(int n) {val = vector<int>(n+10, 0);}
	BIT() {BIT(1);}
	void update(int v, int k) {for(v+=5; v<SZ(val); v+=v&-v) val[v] += k;}
	void update(int a, int b, int k) {update(b+1, -k); update(a, k);}
	int getSum(int v) {int res = 0; for(v+=5; v>0; v-=v&-v) res += val[v]; return res;}
	int getSum(int a, int b) {return getSum(b) - getSum(a-1);}
};

BIT bit;

const int MAX_N = 3e5 + 100, MAX_M = 1e5 + 100;

int N, M;
pi Nr[MAX_N];

int main() {
	cin >> N >> M;
	bit = BIT(M);
	for(int i=0; i<N; i++) scanf("%d%d", &Nr[i].one, &Nr[i].two);
	sort(Nr, Nr+N, [&](pi &x, pi &y) {return x.two - x.one < y.two - y.one;});
	for(int d=1, ix=0; d<=M; d++) {
		while(ix < N && Nr[ix].two - Nr[ix].one + 1 < d) bit.update(Nr[ix].one, Nr[ix].two, 1), ix++;
		int ans = 0;
		for(int i=0; i<=M; i+=d) ans += bit.getSum(0, i);
		printf("%d\n", N-ix + ans);
	}
	return 0;
}
