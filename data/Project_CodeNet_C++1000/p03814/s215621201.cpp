#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    string s;
    cin >> s;
    map<char,int> mp;
    REP(i,s.size()) {
        if(s[i] == 'A') {
            if(mp.count(s[i])) chmin(mp[s[i]],i);
            else mp[s[i]] = i;
        } else if(s[i] == 'Z') {
            if(mp.count(s[i])) chmax(mp[s[i]],i);
            else mp[s[i]] = i;
        }
    }
    cout << mp['Z'] - mp['A'] + 1 << endl;
}