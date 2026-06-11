#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    string s0, s1;
    cin >> s0 >> s1;
    vector<int> ns(0);
    rep(i, n){
        if(s0.at(i) == s1.at(i)){
            ns.push_back(1);
        }else{
            ns.push_back(2);
            i++;
        }
    }
    ll ans;
    if(ns.at(0) == 1){
        ans = 3;
    }else{
        ans = 6;
    }
    rep(i, ns.size()-1){
        if(ns.at(i) == 1 && ns.at(i+1) == 1){
            ans *= 2;
        }else if(ns.at(i) == 1 && ns.at(i+1) == 2){
            ans *= 2;
        }else if(ns.at(i) == 2 && ns.at(i+1) == 1){
            ans *= 1;
        }else if(ns.at(i) == 2 && ns.at(i+1) == 2){
            ans *= 3;
        }
        if(ans >= 1000000007) ans %= 1000000007;
    }
    cout << ans << endl;
    return 0;
}