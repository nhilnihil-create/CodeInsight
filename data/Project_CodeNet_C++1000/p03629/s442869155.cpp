//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <x86intrin.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define V vector
template <typename T> bool chmin(T &a, const T &b) {if(a > b){a = b; return true;} return false;}
template <typename T> bool chmax(T &a, const T &b) {if(a < b){a = b; return true;} return false;}
template<typename A, size_t N, typename T> void Fill (A (&array)[N], const T & val) {fill ((T*)array, (T*)(array+N), val);}
V<int> dx = {-1, 1,  0, 0, -1, -1,  1, 1};
V<int> dy = { 0, 0, -1, 1, -1,  1, -1, 1};

const int INF = 1e9;

int main () {
    string s; cin >> s;
    int n = s.size();
    V<V<int>> ni(n, V<int> (26, n));//ni[i][j]:i文字目(0-indexed)以降に最初にj+'a'が登場するindex
    for (int i = n-1; i >= 0; i--) {
        if (i < n-1) rep(j, 26) ni[i][j] = ni[i+1][j];
        ni[i][s[i] - 'a'] = i;//i文字目以降で最初にs[i]が登場するのはi番目
    }
    V<int> dp(n+1, INF);//dp[i]:i文字目(0-indexed)以降で部分文字列とならない最短の文字列長
    dp[n] = 1;
    V<pair<char, int>> rec(n);//rec[i]:i文字目以降での最初の文字　次のindex
    for (int i = n-1; i >= 0; i--) {
        rep(j, 26) {//先頭の文字をX=j+'a'にする
            if (ni[i][j] == n) {//i以降にXがない
                if (chmin(dp[i], 1)) {//Xだけ
                    rec[i] = {j + 'a', n};
                }
            }
            else {//i以降にXがある
                if (chmin(dp[i], dp[ni[i][j]+1] + 1)) {//ni[i][j]番のかわりにi番を使う 
                    rec[i] = {j + 'a', ni[i][j] + 1};
                }
            }
        }
    }
    int p = 0; 
    while (p != n) {
        cout << rec[p].first;
        p = rec[p].second;
    }
    cout << endl;

    return 0;
}