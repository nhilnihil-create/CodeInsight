#include<iostream>
#include<vector>
#include<string>
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
    int H, W;
    cin >> H >> W;
    vector<string> grid(H);
    for (auto& g : grid) {
        cin >> g;
    }
    vector<int> cnt(26, 0);
    rep(i, 0, H) rep(j, 0, W) {
        ++cnt[grid[i][j] - 'a'];
    }
    rep(i, 0, H / 2) rep(j, 0, W / 2) {
        bool found = false;
        for (auto& c : cnt) {
            if (c >= 4) {
                found = true;
                c -= 4;
                break;
            }
        }
        if (!found) {
            cout << "No" << endl;
            return 0;
        }
    }
    if (H & 1) {
        rep(i, 0, W / 2) {
            bool found = false;
            for (auto& c : cnt) {
                if (c >= 2) {
                    found = true;
                    c -= 2;
                    break;
                }
            }
            if (!found) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    if (W & 1) {
        rep(i, 0, H / 2) {
            bool found = false;
            for (auto& c : cnt) {
                if (c >= 2) {
                    found = true;
                    c -= 2;
                    break;
                }
            }
            if (!found) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}