#include <bits/stdc++.h>
using namespace std;
 
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ", "; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ", "; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ", "; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ", "; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ", "; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ", "; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << ", " << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << ": " << v.second << ", "; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << ": " << v.second << ", "; os << "}"; return os; }
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (q < m) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
#define f first
#define s second
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int len;
    cin >> len;
    vector<bool> arr(8, false);
    int count = 0;
    for(int i = 0; i < len; i++) {
        int a;
        cin >> a;
        if(1 <= a && a <= 399)
            arr[0] = true;
        else if(400 <= a && a <= 799)
            arr[1] = true;
        else if(800 <= a && a <= 1199)
            arr[2] = true;
        else if(1200 <= a && a <= 1599)
            arr[3] = true;
        else if(1600 <= a && a <= 1999)
            arr[4] = true;
        else if(2000 <= a && a <= 2399)
            arr[5] = true;
        else if(2400 <= a && a <= 2799)
            arr[6] = true;
        else if(2800 <= a && a <= 3199)
            arr[7] = true;
        else
            count += 1;
    }
    int ans = 0;
    for(int i = 0; i < 8; i++)
        if(arr[i])
            ans++;
    if(ans == 0)
        cout << 1 << " ";
    else
        cout << ans << " ";
    cout << ans + count;
}