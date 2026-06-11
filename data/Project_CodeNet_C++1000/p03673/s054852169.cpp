#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define int long long
using P = pair<int,int>;
signed main(){
    int n;cin >> n;
    int f = 0;
    int a[n];
    rep(i,n)cin >> a[i];
    vector<int> mae,usi;
    rep(i,n){
        if(f == 0)usi.push_back(a[i]);
        else mae.push_back(a[i]);
        f ^= 1;



    }
    vector<int> ans;
    for(int i = mae.size()-1;i >= 0;i--)ans.push_back(mae[i]);
    for(int i = 0;i < usi.size();i++)ans.push_back(usi[i]);
    if(f)reverse(ans.begin(),ans.end());
    for(auto p:ans)cout << p << " ";
    

    return 0;

}