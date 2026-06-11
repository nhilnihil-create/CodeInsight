/**
*    created: 10.05.2020 09:20:55
**/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int inf =1000000000;

int main() {
    int n;
    ll c, k;
    cin >> n >> c >> k;
    vector<ll> t(n);
    rep(i, n) cin >> t[i];
    sort(t.begin(), t.end());
    //おそらくgreedyでいいけど確証ない
    vector<int> bus;
    int l = 0;
    bool f=1;
    
    rep(i,n){
        if(i==0){
            bus.push_back(t[i] + k);
            l = i;
        }
        if(bus.back()<t[i]||i-l+1>c){
            bus.push_back(t[i] + k);
            l = i;
        }
        //bus[0]=t[0]+K
        //bus[j]=t[i]+K
        //bus[j]<=t[i]&&i-l<=cなら乗車可能
        //bus[j]>k+t[i]||i-l>cのときbus.push
    }
    cout << bus.size() << endl;
}