#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)
const ll mod = 1e9+7;

vector<string> s(2);
 
int main(){
  int n;
  cin >> n;
  cin >> s[0] >> s[1];
  ll res = 1LL;
  bool iscase = true;
  for (int i = 0; i < n;i++){
    if (s[0][i] == s[1][i]){  
      if (i == 0){
        res*=3;
        iscase = true;
        continue;
      }
      else {
        if (iscase) res*=2,res%=mod;
        else res *= 1,res%=mod; 
        iscase = true;
      }
    }
    else{
      i++;
      if (i == 1){
        res*= 6;
        iscase = false;
        continue;
      }
      else {
        if (iscase) res*= 2,res%=mod;
        else res*= 3;res%=mod;
        iscase = false;
      }
    }
  }
  cout << res << endl; 
  return 0; 
}

