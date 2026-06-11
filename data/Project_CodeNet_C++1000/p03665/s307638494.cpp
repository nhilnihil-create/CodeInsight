#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

int main(){
  int n, p;
  cin>>n>>p;
  bool flag=0;
  rep(i,n){
    int a;
    cin>>a;
    if(a%2==1)flag=1;
  }
  ll ans=1;
  rep(i,n-1){
    ans*=2;
  }
  if(flag){
    cout<<ans<<endl;
  }else{
    if(p==1) cout<<0<<endl;
    else cout<<ans*2<<endl;
  }
}