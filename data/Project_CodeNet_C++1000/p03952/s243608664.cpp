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
const int INF = 9e18;

signed main() {
    int N, x;
    cin >> N >> x;
    if (2 <= x && x <= 2 * N - 2) {
        cout << "Yes" << endl;
        set<int> check;
        check.insert(x - 1);
        check.insert(x);
        check.insert(x + 1);
        int count = 0;
        for (int i = 1; i <= 2 * N - 1; i++) {
            if (N - 1 == i) {
                for (int temp : check) {
                    cout << temp << endl;
                }
                i += 2;
                continue;
            }
            while (true) {
                ++count;
                if (check.find(count) == check.end()) {
                    cout << count << endl;
                    break;
                }
            }
        }
    } else {
        cout << "No" << endl;
    }
}
