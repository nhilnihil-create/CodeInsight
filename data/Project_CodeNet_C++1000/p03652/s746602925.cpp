#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

const int INF = 1 << 30;

int N, M;

void dfs(const vector<vector<int>>& A, set<int>& S, int& ans) {
    vector<int> cnt(M, 0);
    rep(i, 0, N) {
        rep(j, 0, M) {
            if (S.count(A[i][j])) {
                ++cnt[A[i][j]];
                break;
            }
        }
    }
    int max_sport;
    int max_participants = 0;
    rep(i, 0, M) {
        if (chmax(max_participants, cnt[i])) {
            max_sport = i;
        }
    }
    chmin(ans, max_participants);
    S.erase(max_sport);
    if (S.size()) {
        dfs(A, S, ans);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    rep(i, 0, N) rep(j, 0, M) {
        cin >> A[i][j];
        --A[i][j];
    }
    int ans = INF;
    set<int> S;
    rep(i, 0, M) {
        S.insert(i);
    }
    dfs(A, S, ans);
    cout << ans << endl;
    return 0;
}