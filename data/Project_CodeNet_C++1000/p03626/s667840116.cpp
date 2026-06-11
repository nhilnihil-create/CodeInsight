#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i, a, b) for(ll i = (a); i < (ll)b; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1000000000000000
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;
typedef pair<ll, ll> p;
constexpr int MOD = 1000000007;

template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

void print(const std::vector<int> &v) {
    std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << " "; });
    std::cout << std::endl;
}
vector<vector<int>> color;
vector<vector<char>> S;
string ALL;
int N;
void bfs(int a, int b) {
    bool flag; //縦
    if(a == 0) {
        if(S[a][b] == S[a + 1][b]) {
            flag = true;
        } else {
            flag = false;
        }
    } else {
        if(S[a][b] == S[a - 1][b]) {
            flag = true;
        } else {
            flag = false;
        }
    }
    if(flag) {
        ALL.push_back('X');
        if(b == N - 1) {
            return;
        }
        bfs(a, b + 1);
    } else {
        ALL.push_back('Y');
        if(b + 2 >= N) {
            return;
        }
        bfs(a, b + 2);
    }
}

int main() {
    cin >> N;
    color.resize(2);
    S.resize(2);
    REP(i, 2) {
        color[i].resize(N);
        S[i].resize(N);
    }
    for(int i = 0; i < N; i++) {
        cin >> S[0][i];
    }
    for(int i = 0; i < N; i++) {
        cin >> S[1][i];
    }

    REP(i, 2) {
        REP(j, N) { color[i][j] = -1; }
    }
    bfs(0, 0);
    // cout << ALL << endl;
    long long res = 1;
    for(int i = 0; i < ALL.size(); i++) {
        if(i == 0) {
            if(ALL[i] == 'X') {
                res *= 3;
            } else {
                res *= 6;
            }
        } else {
            if(ALL[i] == 'Y') {
                if(ALL[i - 1] == 'X') {
                    // XY
                    res *= 2;
                } else {
                    // YY
                    res *= 3;
                }

            } else {
                // X
                if(ALL[i - 1] == 'X') {
                    // XX
                    res *= 2;
                } else {
                    // YX
                    res *= 1;
                }
            }
        }
        res %= MOD;
    }
    cout << res << endl;
    return 0;
}