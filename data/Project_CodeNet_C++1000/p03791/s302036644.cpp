#include <bits/stdc++.h>

#define ll long long

#define pii std::pair<int,int>
#define mp std::make_pair
#define fi first
#define se second

#define SZ(x) (int)(x).size()
#define pb push_back

template<class T>inline void chkmax(T &x, const T &y) {if(x < y) x = y;}
template<class T>inline void chkmin(T &x, const T &y) {if(x > y) x = y;}

template<class T>
inline void read(T &x) {
    char c;int f = 1;x = 0;
    while(((c=getchar()) < '0' || c > '9') && c != '-');
    if(c == '-') f = -1;else x = c-'0';
    while((c=getchar()) >= '0' && c <= '9') x = x*10+c-'0';
    x *= f;
}
static int outn;
static char out[(int)2e7];
template<class T>
inline void write(T x) {
    if(x < 0) out[outn++] = '-', x = -x;
    if(x) {
        static int tmpn;
        static char tmp[20];
        tmpn = 0;
        while(x) tmp[tmpn++] = x%10+'0', x /= 10;
        while(tmpn) out[outn++] = tmp[--tmpn];
    }
    else out[outn++] = '0';
}

const int MOD = 1e9 + 7;

int n;

int main() {
	read(n);
	int ans = 1;
	for(int i = 1, k = 0, x; i <= n; ++i) {
		read(x);
		if(x >= 2 * k + 1) ans = (ll)ans * (++k) % MOD;
		else ans = (ll)ans * (k + 1) % MOD;
	}
	std::cout << ans << std::endl;
    return 0;
}
