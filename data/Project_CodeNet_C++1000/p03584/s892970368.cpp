#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,k;
  cin >> n >> k;
  ll a[n],b[n];
  rep(i,n) cin >> a[i] >> b[i];

  int c=0;
  ll ans=0;
  for(int i=30;i>=0;i--){
    if((1<<i) & k){
      ll tans=0;
      int nc = c |(1<<i);
      rep(j,n){
	if((a[j]|c) < nc){
	  tans+=b[j];
	}
      }
      ans=max(tans,ans);
      c=nc;
      //      cout << bitset<30>(c) << endl;
    }
    if(i==0){
      ll tans=0;
      rep(j,n){
	if((a[j]|c) <= c){
          tans+=b[j];
	}
      } 
      ans=max(tans,ans);      
    }
  }
  cout << ans << endl;


  
  return 0;
    

}
