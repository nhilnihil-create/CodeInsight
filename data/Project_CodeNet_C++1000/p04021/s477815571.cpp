#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto& a : A) {
        cin >> a;
    }
    vector<int> B(A);
    sort(all(B));
    map<int, int> pos_map;
    rep(i, 0, B.size()) {
        pos_map[B[i]] = i + 1;
    }
    vector<int> C(N);
    rep(i, 0, N) {
        C[i] = pos_map[A[i]];
    }
    int ans = 0;
    for (int i = 1; i < N; i += 2) {
        ans += C[i] % 2;
    }
    cout << ans << endl;
    return 0;
}