#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  ll a,b,x;
  cin >> a >> b >> x;
  
  if(a==0) cout << b/x+1;
  else cout << b/x-(a-1)/x;
  
  return 0;
}