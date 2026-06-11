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
    ll N;
    cin >> N;
    vector<ll> yon, gusu, kisu;
    rep(i, 0, N) {
        ll temp;
        cin >> temp;
        if (temp % 4 == 0) {
            yon.push_back(temp);
        }
        else if (temp % 2 == 0) {
            gusu.push_back(temp);
        }
        else {
            kisu.push_back(temp);
        }
    }

    if (kisu.size() == 0) {
        cout << "Yes" << endl;
    }
    else if (kisu.size() <= yon.size()) {
        cout << "Yes" << endl;
    }
    else if (gusu.size() == 0 && kisu.size() - 1 == yon.size()) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;

}