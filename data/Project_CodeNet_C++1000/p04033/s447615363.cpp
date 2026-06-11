#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

int main(){
  ll a,b;
  cin >> a >> b;
  string ans = "";
  if(a>0 && b>0) ans = "Positive";
  else if(a*b <= 0) ans = "Zero";
  else{
    if((b-a)%2 == 1) ans = "Positive";
    if((b-a)%2 == 0) ans = "Negative";
  }
  cout << ans << endl;
}