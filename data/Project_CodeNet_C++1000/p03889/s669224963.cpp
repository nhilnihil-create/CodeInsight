#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= end; --i)
#define iter(i, c) for (auto i = (c).begin(); i != (c).end(); ++i)
#define riter(i, c) for (auto i = (c).rbegin(); i != (c).rend(); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    int N = (int)S.size();
    string SS(S);
    reverse(all(SS));
    rep(i, 0, N) {
        if (SS[i] == 'b') {
            SS[i] = 'd';
        }
        else if (SS[i] == 'd') {
            SS[i] = 'b';
        }
        else if (SS[i] == 'p') {
            SS[i] = 'q';
        }
        else {
            SS[i] = 'p';
        }
    }
    if (S == SS) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}