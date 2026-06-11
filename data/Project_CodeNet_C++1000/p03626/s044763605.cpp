#include <iostream>
using namespace std;
#define MOD 1000000007
int main(){
  int n;cin>>n;
  char A[2][n];
  for(int i = 0; 2 > i; i++){
    for(int j = 0; n > j; j++){
      cin>>A[i][j];
    }
  }
  long long ans = 1;
  bool nw = true;
  for(int i = 0; n > i; i++){
    if(A[0][i] != A[1][i]){
      if(!i){
        ans = 6;
      }else{
        if(nw){
          ans = (ans*3)%MOD;
        }else{
          ans = (ans*2)%MOD;
        }
      }
      i++;
      nw = true;
    }else{
      if(!i){
        ans = 3;
      }else{
        if(!nw)ans = (ans*2)%MOD;
      }
      nw = false;
    }
  }
  cout << ans << endl;
}