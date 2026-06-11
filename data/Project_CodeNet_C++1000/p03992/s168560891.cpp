#include <bits/stdc++.h>
#define int long
#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define IOS cin.tie(0); ios::sync_with_stdio(false)
const int INF = 1e9;
using namespace std;

main() {
    string S; cin >> S;
    rep(i,S.size()){
        cout << S[i];
        if(i==3) cout << " ";
    }
    cout << endl;
}