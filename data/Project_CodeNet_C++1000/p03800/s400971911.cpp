#include <bits/stdc++.h>
#include <vector> 
#include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e9;
const int mod = 1e9+7;

signed main(){
    int n;
    string s;
    cin >> n >> s;
    s+=s;
    bool f = false;
    int x[4] = {0,1,0,1};
    int y[4] = {1,0,0,1};
    int exp[4] = {1,1,0,0};
    int a[n+2];
    rep(p,4) {
        a[0]=x[p];
        a[1]=y[p];
       // cout << a[0] << flush;
        FOR(i,1,n+2) {
            if(s[i]=='o') {
                if(a[i]==0) a[i+1]=a[i-1];
                else a[i+1] = (a[i-1]+1)%2;
            }
            if(s[i]=='x') {
                if(a[i]==0) a[i+1]=(a[i-1]+1)%2;
                else a[i+1] = a[i-1];
            }
            //cout << a[i] << flush;
        }
       // cout << a[n] << endl;
        if(s[0]=='x') {
            exp[p]++;
            exp[p]%=2;
        } 

        if(a[0]==a[n]&&a[1]==a[n+1]){
            rep(i,n) {
            if(a[i]==0) cout << "S" << flush;
            else cout << "W" << flush;
            }
            cout << "" << endl;
            return 0;
        }
    }
    if(!f) cout << -1 << endl;
    else {
        rep(i,n) {
            if(a[i]==0) cout << "S" << flush;
            else cout << "W" << flush;
        }
    cout << "" << endl;
    }
    
    return 0;
}
