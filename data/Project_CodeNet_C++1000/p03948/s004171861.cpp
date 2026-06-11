#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll> P;
#define pb push_back
#define mp make_pair
#define fr(i,n) for(int i=0;i<n;i++)
#define Fr(i,n) for(int i=0;i++<n;)
#define ifr(i,n) for(int i=n-1;i>=0;i--)
#define iFr(i,n) for(int i=n;i>0;i--)

int main(){
  ll n,t,a[100010],m[100010]={(ll)1e10},M=0,ans=0;
  cin>>n>>t;
  Fr(i,n){
    cin>>a[i];
    m[i]=min(m[i-1],a[i]);
    M=max(M,a[i]-m[i]);
  }
  Fr(i,n) if(M==a[i]-m[i]) ans++;
  cout<<ans<<endl;
}