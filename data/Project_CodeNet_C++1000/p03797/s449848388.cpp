#include <bits/stdc++.h>
#define pb push_back
using namespace std;
#define  ll long long
#define mod 1000000007
void solve(){

  ll n,m; cin>>n>>m;
  if(m<=2*n) {
     cout<<m/2<<endl;return ;
  } 
  
  ll k=m-2*n;

  cout<< k/4 + n <<endl; 

    
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
