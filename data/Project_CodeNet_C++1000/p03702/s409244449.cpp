#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,a,b;cin>>n>>a>>b;
  a-=b;
  vector<int> h(n);
  rep(i,n)cin>>h[i];
  int l=0,r=1e9+2;
  while(l+1<r){
      ll mid=(l+r)/2,cnt=0;
      vector<int> k;
      rep(i,n){
          if(h[i]>mid*b)cnt+=(h[i]-mid*b+a-1)/a;
      }
      if(cnt<=mid)r=mid;
      else l=mid;
  }
  cout<<r<<endl;
  return 0;
  }
