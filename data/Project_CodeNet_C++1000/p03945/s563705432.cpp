//url:
//problem name: 

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
    string S;
    cin >> S;
    string res = "";
    int N = S.size();
    int i = 0;
    while(i < N) {
        char c = S[i];
        res += c;
        int j = 1;
        while(c == S[i+j]) {
            j++;
        }
        i += j;
    }
    map<char,int> mp;
    for(char c:res) {
        if(mp.count(c)) mp[c]++;
        else mp[c] = 1;
    }
    int ans;
    if(mp['W'] == 0 || mp['B'] == 0) ans = 0;
    else ans = mp['W'] + mp['B']-1;
    cout << ans << endl;
}
