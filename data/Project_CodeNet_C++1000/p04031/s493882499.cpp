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
  int ave=0;
  rep(i,0,n){
    ave+=a[i];
  }
  ave/=n;
  int x=0;
  rep(i,0,n){
    x+=(a[i]-ave)*(a[i]-ave);
  }
  int y=0;
  rep(i,0,n){
    y+=(a[i]-ave-1)*(a[i]-ave-1);
  }
  cout<<min(x,y)<<endl;
}