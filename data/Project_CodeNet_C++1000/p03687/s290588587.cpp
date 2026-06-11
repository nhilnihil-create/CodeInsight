#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll INF =ll(1e18)+5;

int main() {
    string S;
    cin >> S;
    vector<vector<ll>> place(26);
    for(int i=0;i<S.size();i++){
        int t = S[i] -'a';
        place[t].push_back(i);
    }
    for(int i=0;i<26;i++){
        place[i].push_back(S.size());
    }
    ll ans =INF;
    for(int i=0;i<26;i++){
        ll temp = 0;
        ll last =-1;
        for(ll t:place[i]){
            // cerr <<"t=" << t << endl;
            temp =max(temp,t-last-1);
            last = t;
        }
        // cerr << char('a' +i) << "temp=" << temp <<endl;
        ans = min(temp,ans);
    }
    cout << ans << endl;

    return 0;
}