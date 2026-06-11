#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
#include <ccomplex>
#include <unordered_map>
#include <cstring>
#include <iostream>
#include <numeric>
#include <sstream>
#include <set>
#include <map>
#include <tuple>
#include <iomanip>

using namespace std;
#define MAX 1LL << 60
#define MOD 1000000007
#define BOX 200000

typedef long long ll;

#define rep(i, s, e) for(unsigned int i = s; i < e; i++)
#define repR(i, s, e) for(ll i = s; i > e; i--)
#define reft0(i, j) setfill('0') << setw(i) << j
#define fix(i) fixed << setprecision(i)
#define so(a) sort(begin(a), end(a))
#define soR(a) sort(begin(a), end(a), greater<ll>())
#define sum(a) accumulate(begin(a), end(a), 0)


template<class T> inline bool chMax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chMin(T& a, T b) { if (a > b) { a = b; return true; } return false; }



int main() {
    string s;
    cin >> s;
    string start{ s[0] };
    string end{ s[s.size() - 1] };
    string len = to_string(s.size() - 2);

    cout << start + len + end << endl;

    return 0;

}