//#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
//using namespace atcoder;
#define int long long
   template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
    const int MAX =200005;
const int MOD =1000000007;

signed main(){
  int n,a,b;
  cin>>n>>a>>b;
  int h[n];
  for(int i=0;i<n;i++)cin>>h[i];
  int ng=0,ok=1e9,mid;
  while(abs(ok-ng)>1){
    mid=(ok+ng)/2;
    int c=0;
    for(int i=0;i<n;i++){
      if(h[i]>b*mid)c+=(h[i]-b*mid-1)/(a-b)+1;
    }
    if(c<=mid)ok=mid;
    else ng=mid;
  }
  cout<<ok<<endl;
}