#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

int calc(int a,int b){
  if(a<=b) return b-a;
  return 1001001001;
}

int main(){
  
  ll a,b;
  cin >> a >> b;
  int ans = 1001001001;
  ans = min(ans,calc(a,b));
  ans = min(ans,calc(-a,b)+1);
  ans = min(ans,calc(a,-b)+1);
  ans = min(ans,calc(-a,-b)+2);
  cout << ans << endl;
  
}