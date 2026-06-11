#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;cin >> n;
    vector<vector<ll>> v(n,vector<ll>(2));
    for (int i=0;i<n;i++){
        cin >> v[i][0]>>v[i][1];
    }
    for (int a=0;a<n-1;a++){
        ll cur=1ll*max(v[a][0]/v[a+1][0]+(v[a][0]%v[a+1][0]!=0),v[a][1]/v[a+1][1]+(v[a][1]%v[a+1][1]!=0));
        v[a+1][0]=v[a+1][0]*cur;
        v[a+1][1]=v[a+1][1]*cur;
    }
  //  for(auto u:v)cout<<u[0]<<' '<<u[1]<<endl;
    cout << 1ll*v[n-1][0]+v[n-1][1];
}
