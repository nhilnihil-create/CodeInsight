#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll N;cin >> N;
  ll P;cin >> P;
  ll GU=0,KI=0;
  for(int i=0;i<N;i++){
    int A;cin >> A;
    if(A%2==0){
      GU ++;
    }else{
      KI ++;
    }
  }
  if(KI==1&&GU==0&&P==0){
    cout << 0 << endl;
    return 0;
  }
  ll ans = 1;
  if(KI==0){
    if(P==1){
      cout << 0 << endl;
      return 0;
    }
    ans = 2;
  }
  for(int i=0;i<N-1;i++){
    ans = ans * 2;
  }
  cout << ans << endl;
}