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
const int MOD = 998244353;
const int INF = 9e18;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<list<int>> like(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int sport;
            cin >> sport;
            like[i].push_back(sport);
        }
    }
    int ans = INF;
    for (int i = 0; i < M; i++) {
        map<int, int> check;
        for (int j = 0; j < N; j++) {
            check[*like[j].begin()]++;
        }
        int sport = 0, count = -1;
        {
            auto itr = check.begin();
            while (itr != check.end()) {
                if (count < itr->second) {
                    count = itr->second;
                    sport = itr->first;
                }
                ++itr;
            }
        }
        ans = min(ans, count);
        for (int j = 0; j < N; j++) {
            auto itr = like[j].begin();
            while (itr != like[j].end()) {
                if ((*itr) == sport) {
                    like[j].erase(itr);
                    break;
                }
                ++itr;
            }
        }
    }
    cout << ans << endl;
}
