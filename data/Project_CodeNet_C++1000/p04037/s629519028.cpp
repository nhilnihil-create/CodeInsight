#include <bits/stdc++.h>
//#include <tr1/unordered_map>
//#include"Bignum/bignum.h"
//#define big bignum
#define lowbit(x) (x & -x)
#define debug(x) (cout << "#x = " << (x) << endl)
#define Set(x, i) memset (x, i, sizeof(x))
#define R register
#define For(i, j, k) for(R int i = (j), ED = (k); i <= ED; ++i)
#define Rep(i, j, k) for(R int i = (j), ED = (k); i >= ED; --i)
#define Cross(i, j, k) for(R int i = (j); i; i = (k))
using namespace std;
typedef long long ll;
const ll N = 200011;
const ll INF = 5e16;

namespace IO {

    inline char gc() {
        static char buf[100000], *p1 = buf, *p2 = buf;
        return (p1 == p2) && (p2 = (p1 = buf) +
            fread(buf, 1, 100000, stdin), p1 == p2)? EOF: *p1++;
    }

    #define dd ch = getchar()
    inline ll read() {
        R ll x = 0; R int f = 0; R char dd;
        for (; !isdigit(ch); dd) f ^= (ch == '-');
        for (; isdigit(ch); dd)  x = x * 10 + (ch ^ 48);
        return f? -x: x;
    }
    #undef dd

    inline void write ( ll x ) {
        if (x < 0) x = -x, putchar('-');
        if (x > 9) write(x / 10); putchar(x % 10 | 48);
    }

    inline void wrn ( ll x ) { write(x), putchar(' '); }

    inline void wln ( ll x ) { write(x), putchar('\n'); }

    inline void wlnn ( ll x, ll y ) { wrn(x), wln(y); }

}

using IO::wln;
using IO::read;

namespace Cesare {
	
	/*
		尽量输出 NO .
		 
		必败态是： 
		1. 只剩下一个敌人。
		2. 只剩下一堆，且一堆中敌人数量为偶数。 
		3. 每堆只有一个人，且堆数是偶数。

		2, 3 都可以转移到 1
		什么可以转移到 2, 3 ?
		
		你肯定想最终你操作完为情况 2 ，你的 
		队友不想就这么 gg ，所以肯定会阻止 
		你的操作，即你取到最后两堆奇偶性相 
		同时，如果有奇他会留下奇数堆，如果 
		全部是偶数他就输了。 
		因为如果全都是偶数的话，不管他怎么 
		取，他削减我就取掉，他取掉他还是输。
		所以其实我只需要最后能留出两个偶数 
		堆我就赢了。 
		
		先转化到最接近边界的点，然后判断这个点的状态。 
		如果这个点无论向上还是向右其走道的状态注定是 
		必败状态，他就是必败的，反之必胜。  
	*/
	
	ll T, a[N];
	
	inline bool cmp ( ll a, ll b ) { return a > b; }
	
namespace Subtask {
	
	inline void Solve ( ll n ) {
		For ( i, 1, n ) if (i >= a[i + 1]) {
			ll x = 0;
			for (int j = i + 1; a[j] == i; ++j) x += a[j] == i;
			puts(!(a[i] - i & 1) && !(x & 1)? "Second": "First"); 
			return ;
		}
	}
	
}
	
	int main() {
		ll n = read();
		For ( i, 1, n ) a[i] = read();
		
		sort(a + 1, a + n + 1, cmp); 
		return Subtask :: Solve(n), 0;
	}
	
}

int main()
{
//	freopen("t1.in", "r", stdin);
//	freopen("t1.out", "w", stdout);

	return Cesare :: main();
}

/*
1
5
5 8 4 4 9 
*/





