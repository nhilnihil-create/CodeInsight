#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli h, w;

int main(void){
    cin >> h >> w;
    vector<string> m(h);
    vector<lli> c(26);
    rep(i, h){
        cin >> m[i];
        rep(j, w) c[m[i][j]-'a']++;
    }
    bool ok = true;
    lli s, t, u;
    s = (h%2)*(w%2);
    t = (h%2)*(w/2)+(w%2)*(h/2);
    u = (h*w-s-2*t)/4;
    rep(i, 26){
        while(u > 0 && c[i] >= 4){
            c[i]-=4;
            u--;
        }
    }
    rep(i, 26){
        while(t > 0 && c[i] >= 2){
            c[i]-=2;
            t--;
        }
    }
    if(u > 0 || t > 0) ok = false;

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
