//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T, vector<T>, greater<T> >;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;
template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) { return is >> p.first >> p.second;}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << p.first << ' ' << p.second;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vvi G(n);
    rep(i, n-1) {
        int a;
        cin >> a;
        --a;
        G[a].push_back(i+1);
    }
    function<int(int)> dfs = [&](int now) {
        vi gh;
        for(int ne:G[now]) {
            gh.push_back(dfs(ne));
        }
        sort(rall(gh));
        rep(i, gh.size()) gh[i] += i+1;
        if(gh.empty()) gh.push_back(0);
        return *max_element(all(gh));
    };
    
    cout << dfs(0) << endl;
}