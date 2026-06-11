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
  int n,a[100010]={},ans=0;
  cin>>n;
  Fr(i,n) cin>>a[i];
  Fr(i,n-1){
    if(a[i]==i){swap(a[i],a[i+1]);ans++;}
  }
  if(a[n]==n) ans++;
  cout<<ans<<endl;
}