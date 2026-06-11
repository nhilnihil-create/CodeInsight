#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int64_t pre;
  cin >> pre;
  bool inc=false;
  bool dec=false;
  int64_t A;
  int ans=0;
  for(int i=1;i<N;i++){
    cin >> A;
    if(A>pre){
      if(dec){
        ans++;
        dec=false;
      }else{
        inc=true;
      }
    }else if(A<pre){
      if(inc){
        ans++;
        inc=false;
      }else{
        dec=true;
      }
    }
    pre=A;
  }
  ans++;
  cout << ans << endl;
  return 0;
}
