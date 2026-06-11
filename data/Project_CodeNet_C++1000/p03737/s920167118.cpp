#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>
#include <iomanip>
#include <ctype.h>

using namespace std;
using ll = long long;

#define rep(i,N) for(int i=0;i<(int)N;++i)

ll GCD(ll x, ll y) {
    if (y == 0) return x;
    else return GCD(y, x % y);
}

int main()
{
    string s, t, u;
    cin >> s >> t >> u;

    string S;
    S.push_back(toupper(s[0]));
    S.push_back(toupper(t[0]));
    S.push_back(toupper(u[0]));

    cout << S << endl;
}