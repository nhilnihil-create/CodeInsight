#include <bits/stdc++.h>
#define pb push_back
using namespace std;
#define  ll long long
#define mod 1000000007
void solve(){

  ll n; cin>>n; 
     vector<ll> arr(n+1,0);
     arr[0]=1;
     arr[1]=1;
     for(int i=2;i<=n;i++){
      arr[i]=(i*(arr[i-1])%mod)%mod;
     }
     cout<<arr[n]<<endl;

  }

int main() {
   #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

 ios_base::sync_with_stdio(0);
 cin.tie(0);

  int t =1;  /*cin>>t ;*/

  while(t--){
        solve();
  }

 return 0;
}
