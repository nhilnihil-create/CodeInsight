/// by ztx
/// blog.csdn.net/hzoi_ztx
/// for c++11, using google c++ style
#include <bits/stdc++.h>
#define rep(i, l, r) for (i = (l); i <= (r); i++)
#define rep_(i, l, r) for (i = (l); i < (r); i++)
#define rev(i, r, l) for (i = (r); i >= (l); i--)
#define rev_(i, r, l) for (i = (r); i > (l); i--)
#define Rep(i, l, r) for (int i = (l); i <= (r); i++)
#define Rep_(i, l, r) for (int i = (l); i < (r); i++)
#define Rev(i, r, l) for (int i = (r); i >= (l); i--)
#define Rev_(i, r, l) for (int i = (r); i > (l); i--)
#define each(e, s) for (e : s)
#define Each(e, s) for (auto e : s)
#define r(args...) read(args)
typedef long long ll;
typedef double lf;
typedef long double llf;
typedef unsigned uint;
typedef std::pair<int, int> pii;
int g_ch, g_neg, g_eof;
template <typename ret_t>
inline void read(ret_t& ret) {
    ret = g_ch = g_neg = g_eof = 0;
    while (g_ch < '!') g_ch = getchar();
    if (g_ch == '-') g_neg = true, g_ch = getchar();
    while (g_ch > '!') ret = ret * 10 + g_ch - '0', g_ch = getchar();
    if (g_neg) ret = -ret;
    g_eof = g_ch == EOF;
}
template <typename ret_t, typename... args_t>
inline void read(ret_t& x, args_t&... args) {
    read(x), read(args...);
}

/*
将n拆为(2^k)-1的和
每一个(2^k)-1可以由k+1长度的相同数字的串得到

太长

分为左右两部分，左右长度相同都为L时，算上空串答案数为2^L，
且左右同时在前面或后面添加相同字符，答案*2

所以可以构造使得答案为n+1

从高位开始，两部分同时在前或在后添加相同字符，代表原来的结果*2
如果遇到1，则应该一侧在前面添加字符，另外一个在后面添加相同字符
此时没有字符同时在这个字符前或后，即答案+1
*/

ll n;
int idx;
std::deque<int> l, r;

inline void calc(ll n) {
    if (n == 1) return;
    calc(n >> 1);
    ++idx, l.push_back(idx), r.push_back(idx);
    if (n & 1) ++idx, l.push_front(idx), r.push_back(idx);
}

int main() {
    r(n);
    calc(n + 1);
    printf("%d\n", l.size() + r.size());
    Each(a, l) printf("%d ", a);
    Each(b, r) printf("%d ", b);
    // END:
    getchar(), getchar();
    return 0;
}