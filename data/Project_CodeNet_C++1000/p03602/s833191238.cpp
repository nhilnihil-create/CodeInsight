// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using TP = tuple<ll,ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(18);
}
signed main(){
  init_io();
  ll n,ans=0;
  cin >> n;
  ll a[n][n],ca[n][n];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> a[i][j];
      ca[i][j] = a[i][j];
    }
  }
  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        ca[i][j] = min(ca[i][j],ca[i][k]+ca[k][j]);
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(a[i][j]!=ca[i][j]){
        cout <<"-1\n";
        return 0;
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      bool is_mi = true;
      for(int k=0;k<n;k++){
        if(i==k||k==j) continue;
        if(ca[i][j]==ca[i][k]+ca[k][j]){
          is_mi=false;
          break;
        }
      }
      if(is_mi){
        ans += ca[i][j];
      }
    }
  }
  cout << ans << endl;
}
