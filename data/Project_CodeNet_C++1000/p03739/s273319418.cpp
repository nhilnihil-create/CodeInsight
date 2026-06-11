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
  rep(i,0,n) cin>>a[i];
  ll cur=0;
  ll ans=0;
  rep(i,0,n){
    cur+=a[i];
    if(i%2!=0){
      if(cur>=0){
        ans+=cur+1;
        cur=-1;
      }
    }
    if(i%2==0){
      if(cur<=0){
        ans+=1-cur;
        cur=1;
      }
    }
  }
  ll cur2=0;
  ll ans2=0;
  rep(i,0,n){
    cur2+=a[i];
    if(i%2==0){
      if(cur2>=0){
        ans2+=cur2+1;
        cur2=-1;
      }
    }
    if(i%2!=0){
      if(cur2<=0){
        ans2+=1-cur2;
        cur2=1;
      }
    }
  }
  cout<<min(ans,ans2)<<endl;
}