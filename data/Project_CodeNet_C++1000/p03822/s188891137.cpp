#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.141592653589793
#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define rrep(i, n, k) for (int i = (n); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}
const int MOD = 1e9 + 7;
const int INF = 2e18;

signed main() {
    int N;
    cin >> N;
    vector<vector<int>> tree(N + 1);
    vector<int> ans(N + 1, 0), count(N + 1, 0);
    vector<multiset<int>> save(N + 1);
    for (int i = 2; i <= N; i++) {
        int temp;
        cin >> temp;
        count[temp]++;
        ans[temp]++;
        tree[i].push_back(temp);
    }
    vector<int> check(N + 1, 0);
    queue<int> explore;
    for (int i = 1; i <= N; i++) if (count[i] == 0) explore.push(i);
    while (!explore.empty()) {
        int now = explore.front();
        explore.pop();
        if (check[now] != count[now]) {
            explore.push(now);
            continue;
        }
        int maxValue = 0, temp = 1;
        for (auto itr = save[now].rbegin(); itr != save[now].rend(); itr++) {
            maxValue = max(maxValue, temp++ + *itr);
        }
        ans[now] = maxValue;
        for (auto next : tree[now]) {
            save[next].insert(ans[now]);
            check[next]++;
            if (check[next] == count[next]) explore.push(next);
        }
    }
    cout << ans[1] << endl;
}