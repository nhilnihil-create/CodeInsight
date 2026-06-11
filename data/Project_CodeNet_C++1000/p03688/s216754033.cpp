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

  bool ok;
  int n;
  cin >> n;
  int a[n];
  rep(i,n) cin >> a[i];
  sort(a,a+n);
  
  if(a[0]==a[n-1]){
    if(a[0]==n-1 || a[0]<=n/2) ok=true;
    else ok=false;
  }
  else{
    int min_a=a[0];
    int k;
    rep(i,n){
      if(a[i]!=a[0]){
	k=i;
	break;
      }
    }
    if(k==n-1){
      ok =false;
    }
    else if((n-k)/2+k>=a[n-1] && a[0]>=k) ok=true;
    else ok=false;      
  }
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
    

}
