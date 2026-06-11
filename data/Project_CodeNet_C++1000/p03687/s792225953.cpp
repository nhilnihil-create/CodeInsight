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
    string s;
    cin >> s;
    int len = s.length();
    set<char> unique;
    vector<char> arr;
    for(int i = 0; i < len; i++) {
        if(!unique.count(s[i])) {
            arr.push_back(s[i]);
            unique.insert(s[i]);
        }
    }
    int ans = INT_MAX;
    for(char c : arr) {
        vector<int> pos;
        set<int> p;
        for(int i = 0; i < len; i++) {
            if(s[i] == c) {
                pos.push_back(i);
                p.insert(i);
            }
        }
        int counter = 0;
        int curr = len;
        while(p.size() < curr) {
            int l = p.size();
            for(int i = 0; i < l; i++) {
                if(pos[i] >= curr) {
                    l += 1;
                    continue;
                }
                if(pos[i] != 0 && pos[i] < curr && !p.count(pos[i] - 1)) {
                    pos.push_back(pos[i] - 1);
                    p.insert(pos[i] - 1);
                }
            }
            counter++;
            curr--;
            p.erase(curr);
        }
        if(counter < ans)  
            ans = counter;
    }
    cout << ans;
}