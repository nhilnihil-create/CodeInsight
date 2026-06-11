#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define Fr(i,n) for(int i=0;i++<n;)
#define ifr(i,n) for(int i=n-1;i>=0;i--)
#define iFr(i,n) for(int i=n;i>0;i--)

int main(){
  ll n,a[200010],s=0,ans=1e18,x;
  cin>>n;
  fr(i,n){
    cin>>a[i];
    s+=a[i];
  }
  x=0;
  fr(i,n-1){
    x+=a[i];
    ans=min(ans,abs(s-2*x));
  }
  cout<<ans<<endl;
}