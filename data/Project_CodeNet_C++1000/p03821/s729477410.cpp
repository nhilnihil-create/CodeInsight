#define rep(i,n) for (int i=0;i<n;i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
 
 
int main(){
  int n;
  ll co=0;
  cin >> n;
  vector <ll> a(n);
  vector <ll> b(n);
  
  rep(i,n)
    cin >> a.at(i) >> b.at(i);
  
  rep(i,n){
    a.at(n-i-1)+=co;
    if(a.at(n-i-1)%b.at(n-i-1)==0)
      continue;
    co+=(b.at(n-i-1)-a.at(n-i-1)%b.at(n-i-1));
    //rep(j,n-i)
      //a.at(j)+=(b.at(n-i-1)-a.at(n-i-1)%b.at(n-i-1));
    //cout << co << endl;
    
  }
  cout << co << endl;
    
}