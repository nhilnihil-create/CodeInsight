#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll> P;
#define pb push_back
#define ft first
#define sd second
#define mp make_pair
#define fr(i,n) for(int i=0;i<n;i++)
#define Fr(i,n) for(int i=0;i++<n;)
#define ifr(i,n) for(int i=n-1;i>=0;i--)
#define iFr(i,n) for(int i=n;i>0;i--)

int main(){
  ll n,a[303][303],ans=0;
  cin>>n;
  fr(i,n){fr(j,n){cin>>a[i][j];ans+=a[i][j];}}
  ans/=2;
  fr(i,n){
    fr(j,n){
      if(j<=i) continue;
      bool f=1;
      fr(k,n){
        if(k==i||k==j) continue;
        if(a[i][k]+a[k][j]<a[i][j]){cout<<-1<<endl;return 0;}
        if(f&&a[i][k]+a[k][j]==a[i][j]){ans-=a[i][j];f=0;}
      }
    }
  }
  cout<<ans<<endl;
}