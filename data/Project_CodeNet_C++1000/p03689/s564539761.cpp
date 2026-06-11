#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 1000000000000000000;
#define all(v) v.begin(), v.end()


int main(){
  ll H,W,h,w;
  cin >> H >> W >> h >> w;
  if(H%h==0&&W%w==0){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
    
    if(W%w!=0){
      ll t=W/w+1;
      rep(i,H){
        rep(j,W){
          if(j%w==0){
            cout << t << " ";
          }else if(j%w==w-1){
            cout << -(t+1) << " ";
          }else{
            cout << 0 << " ";
          }
        }
        cout << endl;
      }
    }else{
      ll t=H/h+1;
      rep(i,H){
        rep(j,W){
          if(i%h==0){
            cout << t << " ";
          }else if(i%h==h-1){
            cout << -(t+1) << " ";
          }else{
            cout << 0 << " ";
          }
        }
        cout << endl;
      }
    }
  }
  
}