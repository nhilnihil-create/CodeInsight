#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e13;
const int mod = 1e9+7;
#define ll long long
map<char, int> m;
signed main() {
    string s;
    cin >> s;
    bool f = true;
    if(s.find("N")<s.length()&&s.find("N")>=0) {
        //cout << s.find("W")  << endl;
        if(s.find("S")<0||s.find("S")>=s.length()) {

            f = false;
        }
    }
    if(s.find("S")<s.length()&&s.find("S")>=0) {
        //cout << s.find("W")  << endl;
        if(s.find("N")<0||s.find("N")>=s.length()) {

            f = false;
        }
    }
    if(s.find("W")<s.length()&&s.find("W")>=0) {
        if(s.find("E")<0||s.find("E")>=s.length()) {
            f = false;
        }
    }
    if(s.find("E")<s.length()&&s.find("E")>=0) {
        if(s.find("W")<0||s.find("W")>=s.length()) {
            f = false;
        }
    }
    if(f)cout << "Yes" << endl;
    else cout << "No" << endl;
  return 0;
}

