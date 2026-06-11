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
    int h,w;
    cin >> h >> w;
    rep(i,h) {
        string str;
        cin >> str;
        rep(j,w) {
            m[str[j]]++;
        } 
    }
    if(h%2==0 && w%2==0) {
        for(auto mm: m) {
            if(mm.second%4!=0) {
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
    }else if(h%2&&w%2) {
        map<int, int> ma;
        for(auto mm: m) {
            ma[mm.second%4]++;
        }
        if(ma[1]!=1) {
            cout << "No" << endl;
            return 0;
        }
        if(ma[3]) {
            cout << "No" << endl;
            return 0;
        }
        if(ma[2]<=(h/2+w/2)) {
            cout << "Yes" << endl;
        }
        
    }else {
        if(w%2) swap(h,w); 
        map<int, int> ma;
        for(auto mm: m) {
            ma[mm.second%4]++;
        }
        //cout << ma[2]<<" "<<h/2 << endl;
        if(ma[1]||ma[3]) {
            cout << "No" << endl;
            return 0;
        }
        if(ma[2]<=w/2) {
            //cout << ma[2] << endl;
            cout << "Yes" << endl;
            return 0;
        }
        cout << "No" << endl;
    }

  return 0;
}

