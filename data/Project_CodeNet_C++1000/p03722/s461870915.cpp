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

struct path {
    int from, to, score;
};

signed main() {
    int N, M;
    cin >> N >> M;
    vector<path> edge;
    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        --A;
        --B;
        edge.push_back({A, B, C * -1});
    }
    vector<bool> check(N, false);
    {
        vector<bool> checkS(N, false), checkE(N, false);
        checkS[0] = true;
        checkE[N - 1] = true;
        for (int i = 0; i < N; i++) {
            for (auto e : edge) {
                if (checkS[e.from]) checkS[e.to] = true;
                if (checkE[e.to]) checkE[e.from] = true;
            }
        }
        for (int i = 0; i < N; i++) check[i] = checkS[i] && checkE[i];
    }

    vector<int> ans(N, INF);
    ans[0] = 0;
    for (int i = 0; i < N; i++) {
        for (auto e: edge) {
            if (ans[e.to] > ans[e.from] + e.score) {
                ans[e.to] = ans[e.from] + e.score;
                if (i == N - 1 && check[e.to] && check[e.from]) {
                    cout << "inf" << endl;
                    return 0;
                }
            }
        }
    }
    cout << ans[N - 1] * -1 << endl;
}
