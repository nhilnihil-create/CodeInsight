#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

int main(){
  int n;
  cin>>n;
  ll t1,a1,t2,a2;
  cin>>t1>>a1;
  rep(i,n-1){
    cin>>t2>>a2;
    ll d=(t1+t2-1)/t2;
    if(a1>d*a2){
      d=(a1+a2-1)/a2;
    }
    t1=d*t2;
    a1=d*a2;
  }
  cout<<t1+a1<<endl;
  return 0;
}