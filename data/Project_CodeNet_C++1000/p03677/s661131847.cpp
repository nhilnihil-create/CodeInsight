/*----------------by syr----------------*/
/*

         iii                  ii
     rBQBBBBBBE       BBR iBBBBQBBL     XBBBBBBQBBBBB
   iBBQJ    7BBB      BBsSBBr   BBQ      i      cBBB
  rBBU       iBBw     BBBQi     HBBi           KBBi
  BBH         BB5    iBBB       isL          wBB5
 GBB         iBBi    6BB                   iBBB
 BBQ         BQB     BBD                  QBBi
 BBB        BQB     iQBi                1BBv
 sBBg     wBBB      QBB               iBBB
  7BBBBBBBBBi       BBR              wBBBBBBBBBBBBB
     irvi           ii               ii    i i iii
                i5U
               BBB
               BB7
              1BB
      iPBBBBBKBBR    JBR1       rQBO   BR  UBQP  iBBQi
    7BBBGs7sXBBBi     QBBr     gBBE   rBB BB2BB7HBZQBB
   QBBi      sBQ       BBB   iBBB     SQBBR  BBBB  cBQ
  gBQ        BBg        BBB KBBi      MBBH   BBB   BBs
 iBBv       iBBi         QBBBL        BBR   pBB   iBB
 pBB        BBB         iBBBB        iBB    BBL   KBB
 MBB       BBBR        BBB JBBi      DBR   iBQ    BBL
 GBB     7BBBB2      PBBH   BBBi     BQr   DBB   iBB
  BQBXwgBBP BB7    1BBB      BBQ7   1BB    BBc   BBB
   2BBBBw   BB    EBBS        QBBi  HBa   iBB    BB7
*/
#include<bits/stdc++.h>

using namespace std;

#define PH push
#define MP make_pair
#define PB push_back
#define fst first
#define snd second
#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define x0 x0123456789
#define y0 y0123456789
#define x1 x1234567890
#define y1 y1234567890
#define x2 x2345678901
#define y2 y2345678901
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1e9 + 7;
const int maxn = 1e5 + 5;

int n, m;
int a[maxn];
ll ans;

class SegmentTree{
private:
	int siz;
	ll fir[maxn << 2], dif[maxn << 2];
public:
	int size(){return siz;}
	void init(int _siz){
		for(siz = 1; siz < _siz; siz <<= 1);
		return;
	}
	void update(int x, int l, int r, int s, int t, int f, int d){
		if(s > t)
			return;
		if(l >= s && r <= t){
			fir[x] += f + 1ll * d * (l - s);
			dif[x] += d;
			return;
		}
		int md = l + r >> 1;
		if(s <= md)
			update(x << 1, l, md, s, t, f, d);
		if(t > md)
			update(x << 1 | 1, md + 1, r, s, t, f, d);
		return;
	}
	ll query(int x, int l, int r, int y){
		if(l == r)
			return fir[x];
		int md = l + r >> 1;
		if(y <= md)
			return query(x << 1, l, md, y) + fir[x] + dif[x] * (y - l);
		else
			return query(x << 1 | 1, md + 1, r, y) + fir[x] + dif[x] * (y - l);
	}
}seg;

int main(){
	scanf("%d%d", &n, &m);
	seg.init(m + 1);
	FOR(i, 0, n)
		scanf("%d", a + i);
	FOR(i, 1, n){
		int x = a[i - 1], y = a[i];
		if(y >= x){
			seg.update(1, 0, seg.size() - 1, x + 1, y, 0, 1);
		}
		else{
			seg.update(1, 0, seg.size() - 1, x + 1, m, 0, 1);
			seg.update(1, 0, seg.size() - 1, 1, y, m - x, 1);
		}
	}
	REP(i, 1, m){
		ans = max(ans, seg.query(1, 0, seg.size() - 1, i));
	}
	ans = - ans;
	FOR(i, 1, n){
		if(a[i - 1] <= a[i])
			ans += a[i] - a[i - 1];
		else
			ans += m - a[i - 1] + a[i];
	}
	printf("%lld\n", ans);
	return 0;
}