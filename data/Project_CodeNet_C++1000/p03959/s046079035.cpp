#include<bits/stdc++.h>
using namespace std;
namespace fdata
{
inline char nextchar()
{
    static const int BS = 1 << 21;
    static char buf[BS], *st, *ed;
    if (st == ed)
        ed = buf + fread(st = buf, 1, BS, stdin);
    return st == ed ? -1 : *st++;
}
#ifdef lky233
#define nextchar getchar
#endif
template <typename Y>
inline void poread(Y &ret)
{
    ret = 0;
    char ch;
    while (!isdigit(ch = nextchar()))
        ;
    do
        ret = ret * 10 + ch - '0';
    while (isdigit(ch = nextchar()));
}
#undef nextcar
} // namespace fdata
using fdata::poread;
const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;
int n;
int T[MAXN], A[MAXN];
int  h[MAXN];
signed main()
{
#ifdef lky233
	freopen("testdata.in",  "r", stdin);
	freopen("testdata.out", "w", stdout);
#endif
	poread(n);
	for(register int i = 1; i <= n; ++i)
		poread(T[i]);
	for(register int i = 1; i <= n; ++i)
		poread(A[i]);
	for(register int i = 1; i <= n; ++i)
		if(T[i] != T[i - 1])
			h[i] = T[i];
	for(register int i = n; i >= 1; --i)
		if(A[i] != A[i + 1])
			h[i] = A[i];
	for(register int i = 1, mx = 0; i <= n; ++i)
	{
		mx = max(h[i], mx);
		if(mx != T[i])
		{
			puts("0");
			return 0;
		}
	}
	for(register int i = n, mx = 0; i >= 1; --i)
	{
		mx = max(h[i], mx);
		if(mx != A[i])
		{
			puts("0");
			return 0;
		}
	}
	int ans = 1;
	for(register int i = 1; i <= n; ++i)
	{
		if(!h[i])
		{
			ans = (long long) ans * min(A[i],T[i]) % MOD;
		}
	}
	cerr << ans << endl;
	cout << ans << endl;
}
