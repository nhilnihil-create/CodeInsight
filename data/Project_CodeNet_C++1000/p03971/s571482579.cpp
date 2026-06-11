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
    int n,a,b;
    string str;
    cin >> n >> a >> b;
    cin >> str;
    int total = 0;
    int bc = 0;
    rep(i,n) {
        if(str[i]=='c') {
            cout << "No" << endl;
            continue;
        }
        if(str[i]=='b' && bc<b && total<(a+b)) {
            total++;
            bc++;
            cout << "Yes" << endl;
        }else if(str[i]=='a'&& total<(a+b)) {
            total++;
            cout << "Yes" << endl;
        }else
        {
            cout << "No" << endl;
        }
        
    }

  return 0;
}

