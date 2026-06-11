#include <bits/stdc++.h>

using namespace std;

using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e18;

int main() {
    ll n, m, i, j, k;
    string s,t;
    cin >> s >> t;
    cin >> n;
    ll ss=s.size(),ts=t.size();
    ll sacnt[ss+1]={},sbcnt[ss+1]={};
    ll tacnt[ts+1]={},tbcnt[ts+1]={};
    for(i=0;i<ss;i++){
        if(s[i]=='A')sacnt[i+1]++;
        else sbcnt[i+1]++;
    }
    for(i = 0; i < ts; i++) {
        if(t[i] == 'A')
            tacnt[i + 1]++;
        else
            tbcnt[i + 1]++;
    }
    for(i=0;i<ss;i++){
        sacnt[i+1]+=sacnt[i];
        sbcnt[i+1]+=sbcnt[i];
    }
    for(i = 0; i < ts; i++) {
        tacnt[i + 1] += tacnt[i];
        tbcnt[i + 1] += tbcnt[i];
    }
    for(i=0;i<n;i++){
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        ll sa = sacnt[b]-sacnt[a-1];
        ll sb = sbcnt[b]-sbcnt[a-1];
        ll ta = tacnt[d] - tacnt[c - 1];
        ll tb = tbcnt[d] - tbcnt[c - 1];
        if((sa + sb * 2) % 3 == (ta + tb * 2) % 3){
            cout << "YES" << endl;
        }else {
            cout << "NO" << endl;
        }
    }
    return 0;
}