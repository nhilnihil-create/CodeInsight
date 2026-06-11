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
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N + 1);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    vector<bool> check(N + 1, false);
    auto judge = [&](int now) {
        for (auto temp : G[now]) {
            if (check[temp]) continue;
            check[temp] = true;
            return temp;
        }
        return -1LL;
    };
    deque<int> ans;
    ans.push_back(1);
    check[1] = true;
    while (true) {
        int left = judge(*ans.begin());
        if (left != -1) {
            ans.push_front(left);
            continue;
        }
        int right = judge(*ans.rbegin());
        if (right != -1) {
            ans.push_back(right);
            continue;
        }
        break;
    }
    cout << ans.size() << endl;
    for (auto itr = ans.begin(); itr != ans.end(); itr++) {
        cout << *itr << (itr == next(ans.end(), -1) ? '\n' : ' ');
    }
}