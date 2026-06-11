#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n, in;
    ll n0 = 0;
    ll n1 = 0;
    ll n2 = 0;
    cin >> n;
    vector<int> ns(n);
    rep(i, n){
        cin >> ns.at(i);
    }
    sort(ns.begin(), ns.end());
    vector<int> ans2(0);
    vector<int> ans4(0);
    rep(i, n-1){
        if(ns.at(i) == ns.at(i+1) && n1 != ns.at(i)){
            ans2.push_back(ns.at(i));
            n0 = n1;
            n1 = ns.at(i);
        }
    }
    rep(i, n-3){
        if(ns.at(i) == ns.at(i+1) && ns.at(i+1) == ns.at(i+2) && ns.at(i+2) == ns.at(i+3) && n2 != ns.at(i)){
            ans4.push_back(ns.at(i));
            n2 = ns.at(i);
        }
    }
    cout << max(n0*n1, n2*n2) << endl;
    return 0;
}