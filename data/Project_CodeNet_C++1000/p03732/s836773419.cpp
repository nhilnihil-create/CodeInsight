#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(){
  ll n,W;
  cin >> n >> W;
  ll w,v,w1;
  cin >> w1 >> v;
  vector<ll> a[4];
  a[0].push_back(v);
  for(int i=1;i<n;i++){
    cin >> w >> v;
    a[w-w1].push_back(v);
  }
  for(int i=0;i<4;i++){
    sort(a[i].begin(),a[i].end());
    reverse(a[i].begin(),a[i].end());
  }
  vector<ll>b[4];
  for(int i=0;i<4;i++)if(!a[i].empty())b[i].push_back(a[i][0]);
  for(int i=0;i<4;i++){
    for(int j=1;j<(int)a[i].size();j++){
      b[i].push_back(b[i][j-1]+a[i][j]);
    }
  }
  ll ret = 0;
  ll wsum = 0;
  ll vsum = 0;
  for(int i=-1;i<(int)a[0].size();i++){
    wsum=0;
    vsum=0;
    if(i!=-1){
      wsum=w1*(i+1);
      vsum=b[0][i];
    }
    if(wsum>W)break;
    for(int j=-1;j<(int)a[1].size();j++){
      ll wsum1 = wsum;
      ll vsum1 = vsum;
      if(j!=-1){
        wsum1+=(w1+1)*(j+1);
        vsum1+=b[1][j];
      }
      if(wsum1>W)break;
      for(int k=-1;k<(int)a[2].size();k++){
        ll wsum2 = wsum1;
        ll vsum2 = vsum1;
        if(k!=-1){
          wsum2+=(w1+2)*(k+1);
          vsum2+=b[2][k];
        }
        if(wsum2>W)break;
        for(int h=-1;h<(int)a[3].size();h++){
          ll wsum3 = wsum2;
          ll vsum3 = vsum2;
          if(h!=-1){
            wsum3+=(w1+3)*(h+1);
            vsum3+=b[3][h];
          }
          //cout << wsum3 << " " << vsum3 << endl;
          if(wsum3<=W)ret = max(ret,vsum3);
        }
      }
    }
  }
  cout << ret << endl;
  return 0;
}
