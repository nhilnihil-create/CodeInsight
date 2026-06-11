#include<iostream>
#include<vector>
#include<string>
#include<map>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<int> X(N);
    for (auto& x : X) {
        cin >> x;
    }
    vector<map<int, int>> mods(M);
    for (auto& x : X) {
        ++mods[x % M][x];
    }
    int ans = 0;
    rep(m, 0, M / 2 + 1) {
        if (m == (M - m) % M) {
            int sum = 0;
            for (auto& i : mods[m]) {
                sum += i.second;
            }
            ans += sum / 2;
        }
        else {
            int sum1 = 0, sum2 = 0;
            for (auto& i : mods[m]) {
                sum1 += i.second;
            }
            for (auto& i : mods[M - m]) {
                sum2 += i.second;
            }
            if (sum1 > sum2) {
                int cnt = 0;
                for (auto& i : mods[m]) {
                    cnt += i.second / 2;
                }
                ans += sum2;
                ans += min(cnt, (sum1 - sum2) / 2);
            }
            else {
                int cnt = 0;
                for (auto& i : mods[M - m]) {
                    cnt += i.second / 2;
                }
                ans += sum1;
                ans += min(cnt, (sum2 - sum1) / 2);
            }
        }
    }
    cout << ans << endl;
    return 0;
}