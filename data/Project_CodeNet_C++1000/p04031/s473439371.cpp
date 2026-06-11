/**
*    created: 16.07.2020 01:46:22
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using bint = boost::multiprecision::cpp_int;
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pcnt(bit) __builtin_popcountll(bit)
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b; return 1;} return 0;}
const long double pi = acos(-1.0);
const int MAX = 1000010;
const int INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    map<int,int> mp;
    vector<int> v;
    int sum = 0;
    rep(i,n) {
        int a; cin >> a;
        mp[a]++;
        v.push_back(a);
        sum += a;
    }
    if (mp.size() == 1) {cout << 0 << endl; return 0;}
    int m1 = sum/n;
    int m2 = m1+1;
    int t1 = 0;
    int t2 = 0;
    rep(i,n) t1 += (v[i]-m1) * (v[i]-m1);
    rep(i,n) t2 += (v[i]-m2) * (v[i]-m2);
    cout << min(t1,t2) << endl;
    return 0;
}