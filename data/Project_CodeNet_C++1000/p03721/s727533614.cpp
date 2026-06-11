#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    ll n,k;
    cin >> n >> k;
    vector<pii> x(n);
    rep(i,n){
        int a,b;
        cin >> a >> b;
        x[i].first = a;
        x[i].second = b;
    }
    sort(x.begin(),x.end());
    rep(i,n){
        k -= x[i].second;
        if(k <= 0){
            cout << x[i].first << endl;
            return 0;
        }
        else continue;
    }
}