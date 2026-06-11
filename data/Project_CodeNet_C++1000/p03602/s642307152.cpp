#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define MOD 1000000007

const ll INF=LLONG_MAX/2;

int main(){
  int N;
  cin>>N;
  ll a[N][N];
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++) cin>>a[i][j];
  }
  for(int k=0;k<N;k++){
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        if(a[i][j]>a[i][k]+a[k][j]){
          cout<<-1<<endl;
          return 0;
        }
      }
    }
  }
  for(int k=0;k<N;k++){
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        if(k==j||k==i) continue;
        if(a[i][j]==a[i][k]+a[k][j]) a[i][j]=INF;
      }
    }
  }
  ll ans=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++) ans+=(a[i][j]!=INF?a[i][j]:0);
  }
  cout<<ans/2<<endl;
  return 0;
}
