#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n, w; cin>>n>>w;
  vector<int> v[4];
  int w_1;
  for (int i=0; i<n; i++) {
    int wi,vi; cin>>wi>>vi;
    if (i==0) w_1=wi;
    v[wi-w_1].push_back(vi);
  }

  for (int i=0; i<4; i++) {
    sort(v[i].begin(), v[i].end());
    v[i].push_back(0);
    reverse(v[i].begin(), v[i].end());
    for (int j=1; j<v[i].size(); j++) v[i][j]+=v[i][j-1];
  }

  int ans=0;
  for (ll w0=0; w0<v[0].size(); w0++) {
    for (ll w1=0; w1<v[1].size(); w1++) {
      for (ll w2=0; w2<v[2].size(); w2++) {
        for (ll w3=0; w3<v[3].size(); w3++) {
          ll tmp=w0*(w_1)+w1*(w_1+1)+w2*(w_1+2)+w3*(w_1+3);
          if (tmp<=w) {
            ans=max(ans, v[0][w0]+v[1][w1]+v[2][w2]+v[3][w3]);
          }
        }
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}