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

  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n)cin >> a[i];

  int lb = 1;
  ll ans=0;

  rep(i,n){
    if(a[i]==lb) lb++;
    else if(a[i]>lb){
      ans += (a[i]-1)/lb;
      if(i==0) lb++;
    }    
  }
  cout << ans << endl;
  
  return 0;
    

}
