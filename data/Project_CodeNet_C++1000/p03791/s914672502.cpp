#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <cstring>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <array>
#include <tuple>
#include <utility>
#include <cctype>
#include <typeinfo>
using namespace std;

#define len(x)  (int((x).size()))
#define append push_back
#define pp make_pair
#define ff(a, b)    for (int a = 0; a < int(b); ++a)
#define ii(n)    ff(i, n)
#define kk(n)    ff(k, n)
#define mm(n)    ff(m, n)
#define fff(a, b, c) for (int a = int(b); a < int(c); ++a)
#define iii(a, b) fff(i, a, b)
#define kkk(a, b) fff(k, a, b)
#define mmm(a, b) fff(m, a, b)
#define xx first
#define yy second
#define bb begin()
#define ee end()
#define all(x)  (x).bb, (x).ee
#define ite(v)   decltype((v).bb)
#define fe(i, v) for(ite(v) i = (v).bb; i != (v).ee; ++i)
#define err(...)    { fprintf(stderr, __VA_ARGS__); fflush(stderr); }

using LL = long long;
using pii = pair<int, int>;


const LL INF = 9223372036854775807LL;
//const int INF = 2147483647;
   
const LL MOD = LL(1e9) + 7;




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout << '\n';
    

    int N;
    cin >> N;
    vector<LL> xs(N);
    ii (N)
        cin >> xs[i];

    xs[0] = 1;
    LL full = 1;
    LL add = 0;
    vector<LL> adds(N, 0);
    iii (1, len(xs)) {
        adds[i] = add;
        LL x = xs[i];
        if (full <= x-2) {
            full += 2;
        } else {
            ++add;
        }
    }

    LL rr = 1;
    for (int i = N-1; i >= 0; --i) {
        LL places = N - adds[i];
        LL allocated = N-1 - i;
        rr = (rr * (places - allocated)) % MOD;
    }

    cout << rr << '\n';

    return 0;
}

