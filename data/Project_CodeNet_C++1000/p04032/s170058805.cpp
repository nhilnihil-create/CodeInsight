#include <bits/stdc++.h>
#define long long long
//#include <ext/numeric>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define oo 0x3f3f3f3f
//#define OO 0x3f3f3f3f3f3f3f3f
//#define popcount(n) __builtin_popcount(n)
//#define popcountll(n) __builtin_popcountll(n)

using namespace std;

//using namespace __gnu_cxx;
//using namespace __gnu_pbds;
//template<typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//struct mul {
//    long operator()(const long &n1, const long &n2) const {
//        return (n1 * n2) % Mod;
//    }
//};
//
//long identity_element(const mul &m) {
//    return 1LL;
//}

//long rand_int(long l, long r) { //[l, r]
//    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
//    return uniform_int_distribution<long>(l, r)(gen);
//}

const double PI = acos(-1.0);


int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.txt", "rt", stdin);
    //    freopen("friday.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(10), cout << fixed;

    string str;
    cin >> str;
    for (int i = 0; i < (int) str.size() - 1; ++i) {
        if (str[i] == str[i + 1]) {
            cout << i + 1 << ' ' <<  i + 2 << '\n';
            return 0;
        }
        if (i < (int)str.size() - 2 && str[i] == str[i + 2]) {
            cout << i + 1 << ' ' <<  i + 3 << '\n';
            return 0;
        }
    }

    cout << -1 << ' ' << -1 << '\n';


    return 0;
}