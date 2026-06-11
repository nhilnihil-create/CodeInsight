#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <functional>
#include <utility>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> v(n, 0);
  vector<int> peo((n + 1) /2, 0);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }  
  long long q = pow(10, 9) + 7;
  long long ans = 1; 

  sort(v.begin(), v.end());
  if(n % 2 == 1){
    bool f = false;
    for(int i = 0; i < n; i++){
      if(i == 0){if(v[i] != 0){f = true; break;}}
      else if(i % 2 == 1){if(v[i] != i + 1){f = true; break;}}
      else{if(v[i] != i){f = true; break;}}
      }
    if(f){cout << 0 << endl;}
    else{
      while(n > 1){
        ans *= 2;
        ans %= q;
        n -= 2;
      }
      cout << ans << endl;
      }
  }
  else{
    bool f = false;
    for(int i = 0; i < n; i++){
      if(i % 2 == 0){if(v[i] != i + 1){f = true; break;}}
      else{if(v[i] != i){f = true; break;}}
    }
    if(f){cout << 0 << endl;}
    else{
      while(n > 0){
        ans *= 2;
        ans %= q;
        n -= 2;
      }
      cout << ans << endl;
      
    }
  }
    
  

}