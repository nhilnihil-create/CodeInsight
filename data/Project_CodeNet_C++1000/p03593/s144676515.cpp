#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
ll const INF = 1LL << 60;
ll const MAX_N = 100000;
ll const MOD = 1000000007;

int main() {
    ll H, W;
    cin >> H >> W;
    vector<vector<char>> a(H, vector<char>(W, 0));
    rep(i, H) {
        rep(j, W) { cin >> a[i][j]; }
    }

    map<char, ll> cnt;

    rep(i, H) {
        rep(j, W) { cnt[a[i][j]]++; }
    }

    ll h_four = floor(H / 2) * floor(W / 2);
    rep(i, h_four) {
        repv(cnt) {
            char c = (*it).first;
            if ((*it).second >= 4) {
                (*it).second -= 4;
                break;
            }
        }
        // cout << "cnt: " << endl;
        // repv(cnt) cout << (*it).first << "," << (*it).second << endl;
    }

    if (H % 2 == 1) {
        ll h_two = floor(W / 2);
        rep(i, h_two) {
            repv(cnt) {
                char c = (*it).first;
                if ((*it).second >= 2) {
                    (*it).second -= 2;
                    break;
                }
            }
        }
        // cout << "cnt: " << endl;
        // repv(cnt) cout << (*it).first << "," << (*it).second << endl;
    }

    if (W % 2 == 1) {
        ll h_two = floor(H / 2);
        rep(i, h_two) {
            repv(cnt) {
                char c = (*it).first;
                if ((*it).second >= 2) {
                    (*it).second -= 2;
                    break;
                }
            }
        }
        // cout << "cnt: " << endl;
        // repv(cnt) cout << (*it).first << "," << (*it).second << endl;
    }

    if (H % 2 == 1 && W % 2 == 1) {
        repv(cnt) {
            char c = (*it).first;
            if ((*it).second >= 1) {
                (*it).second -= 1;
                break;
            }
        }
        // cout << "cnt: " << endl;
        // repv(cnt) cout << (*it).first << "," << (*it).second << endl;
    }

    bool flg = true;
    repv(cnt) {
        if ((*it).second != 0) {
            flg = false;
            break;
        }
    }

    if (flg) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    // cout << "cnt: " << endl;
    // repv(cnt) cout << (*it).first << "," << (*it).second << endl;
    return 0;
}
