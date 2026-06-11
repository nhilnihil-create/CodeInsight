#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<p> ratio;
    for(int i = 0; i < n; i++){
        int t, a;
        cin >> t >> a;
        ratio.push_back(p(t, a));
    }
    ll ans = 0;
    ll tt = 1, aa = 1;
    for(int i = 0; i < n; i++){
        ll n, tmpt = ratio[i].first, tmpa = ratio[i].second;
        n = max((tt + tmpt - 1)/tmpt, (aa + tmpa - 1)/tmpa);
        tt = n*tmpt;
        aa = n*tmpa;
    }
    cout << tt + aa << endl;
}
