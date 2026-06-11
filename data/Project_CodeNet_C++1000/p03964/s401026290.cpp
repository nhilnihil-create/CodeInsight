#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n;
  cin>>n;
  ll x=1;
  ll y=1;
  rep(i,0,n){
    int t,a;
    cin>>t>>a;
    ll b,c;
    b=(t+x-1)/t*t;
    c=(a+y-1)/a*a;
    if(b/t*a>=c){
      x=b;
      y=b/t*a;
    }
    else{
      x=c/a*t;
      y=c;
    }
  }
  cout<<x+y<<endl;
}
