#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=(ll)1e9;
const ll MOD=(ll)1e9+7;
vector<int> dx={1,0,-1,0},dy={0,1,0,-1};

int main(){
  ll H,W,N,c=0;
  cin>>H>>W>>N;
  ll a[N];
  ll ans[H][W];
  for(ll i=0;i<N;i++) cin>>a[i];

  for(ll i=0;i<H;i++){
    for(ll j=0;j<W;j++){
      if(a[c]==0) c++;
      if(i%2==0) ans[i][j]=c+1;
      else ans[i][W-j-1]=c+1;
      a[c]--;
    }
  }
  for(ll i=0;i<H;i++){
    for(ll j=0;j<W;j++){
      cout<<ans[i][j];
      if(j!=W-1) cout<<" ";
    }
    cout<<endl;
  }
}
