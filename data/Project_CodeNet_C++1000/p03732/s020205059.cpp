#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,W,ans=0,w0;
    cin >> n >> W;
    vector<ll> v[4];
    for(int i = 0;i < n;i ++){
        ll x,y;
        cin >> x >> y;
        if(!i) v[0].push_back(y),w0=x;
        else{
            v[x-w0].push_back(y);
        }
        
    }
    for(int i = 0;i < 4;i ++){
        sort(v[i].begin(),v[i].end());
    }
    vector<ll> s[4];
    for(int i = 0;i < 4;i ++){
        s[i].push_back(0);
        for (int j = v[i].size()-1;j >= 0;j --){
            s[i].push_back(s[i].back()+v[i][j]);
        }
    }
    for(int i0 = 0;i0 <= v[0].size();i0 ++){
        for(int i1 = 0;i1 <= v[1].size();i1 ++){
            for(int i2 = 0;i2 <= v[2].size();i2 ++){
                for(int i3 = 0;i3 <= v[3].size();i3 ++){
                     ll sumv = s[0][i0]+s[1][i1]+s[2][i2]+s[3][i3];
                     ll sumw = i0*w0+i1*(w0+1)+i2*(w0+2)+i3*(w0+3);
                     if(sumw<=W) ans = max(ans,sumv);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}