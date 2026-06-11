#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int a, b, c, d;
  int ans;
  cin >> a >> b >> c >> d;
  if(b <= c ||  d <= a){
    //cout << 0 << endl;
    ans = 0;
  }else{
    // c < b
    if(a < c && c < b && b < d){
      ans = b - c;
    }else if(a < c && d <= b){
      ans = d - c;
    }else if( c <= a && d < b){
      ans = d - a;
    }else{
      ans = b - a;
    }

  }
  cout << ans << endl;
  return 0;
}
