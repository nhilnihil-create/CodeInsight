#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define pb push_back
#define FOR(i,S,E) for(int i=S; i<E; i++)
#define rii(x,y) scanf("%d%d", &x, &y)
#define fst first
#define snd second
#define mp make_pair

const int MAXN = 3e5+10, MAXM = 1e5+10;


class FenwickTree {
private: vi ft;
public: FenwickTree(int n) {ft.assign(n+1, 0);}// init n+1 0s
	// Least Significant One-Bit
	static int LSOne(int i) {
		return (i & (-i));
	}
	// range sum query
	int rsq(int b) {
		int sum = 0;
		for(; b; b -= LSOne(b))
			sum += ft[b];
		return sum;
	}
	// range sum query in [a, b]
	int rsq(int a, int b) {
		return rsq(b) - (a == 1 ? 0 : rsq(a-1));
	}
	// adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
	void upd(int k, int v) {
		for(; k < (int)ft.size(); k += LSOne(k)) {
			ft[k] += v;
		}
	}
};

bool comp(ii &a, ii &b) {
    return a.snd-a.fst < b.snd-b.fst;
}

int N, M;
bool debug = 0;
vii query;
int main(int argc, char *argv[]) {
    if (argc > 1) debug = argv[1][0] - '0';
    rii(N, M);
    FenwickTree posR(M), posL(M);
    FOR(i,0,N) {
        int l, r;
        rii(l, r);
        query.pb({l,r});
    }
    sort(query.begin(), query.end(), comp);
    int idx=0;
    FOR(k,1,M+1) {
        if (debug)
            printf("k: %d\n", k);
        // actualizamos los BIT
        for(; idx<N; idx++) {
            ii p = query[idx];
            if (p.snd-p.fst+1 > k) break;
            posR.upd(p.snd, 1);
            posL.upd(p.fst, 1);
        }
        int ans=0;
        for(int i=k; i<=M; i += k) {
            ans += posL.rsq(i) - posR.rsq(i-1);
            if (debug)
                printf("\tans: %d\n", ans);
        }
        printf("%d\n", ans+N-idx);
    }
}
