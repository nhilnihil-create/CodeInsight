/**
*    author:  souzai32
*    created: 14.08.2020 12:51:05
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    int k,t;
    cin >> k >> t;
    vector<int> a(t);
    rep(i,t) cin >> a.at(i);
    sort(a.begin(),a.end(),greater<>());

    int ans=0;
    if(a.at(0)>(k+1)/2) ans+=2*(a.at(0)-(k+1)/2)-(k+1)%2; 

    cout << ans << endl;

    return 0;
}