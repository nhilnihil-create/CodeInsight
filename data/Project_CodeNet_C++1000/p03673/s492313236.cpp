#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n;
  cin>>n;
  int a[n];
  rep(i,0,n){
    cin>>a[i];
  }
  int b[n];
  if(n%2==0){
    rep(i,0,n/2){
      b[n/2+i]=a[2*i];
    }
    rep(i,0,n/2){
      b[n/2-1-i]=a[2*i+1];
    }
  }
  else{
    rep(i,0,n/2+1){
      b[n/2-i]=a[2*i];
    }
    rep(i,0,n/2){
      b[n/2+1+i]=a[2*i+1];
    }
  }
  rep(i,0,n) cout<<b[i]<<endl;
}