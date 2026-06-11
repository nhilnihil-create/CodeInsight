#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n,k; cin >> n >> k;
    vector<pair<int,int>> a(n);
    for(int ix=0;ix<n;ix++){
        int x,y;
        cin >> x >> y;
        a.at(ix) = make_pair(x,y);
    }
    sort(a.begin(),a.end());
    ll cnt=0,ans = -1;
    int i=0;
    while(cnt < k){
        cnt += a.at(i).second;
        if(cnt >= k) ans = a.at(i).first;
        i++;
    }
    cout << ans << endl;
}