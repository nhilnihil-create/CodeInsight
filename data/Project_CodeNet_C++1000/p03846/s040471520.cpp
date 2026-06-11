#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A.at(i);
  }
  
  map<int, int> cnt;
  for (int x : A) {
    if (cnt.count(x)) {
      cnt.at(x)++;
    } 
    else {
      cnt[x] = 1;
    }
  }
  
  bool ans = true;
  
  if(n%2 == 0){
    for (auto x : cnt) {
      if(x.first == 0){
        ans = false;
      }
      else if(x.second != 2){
        ans = false;
      }
    }
  }
  
  if(n%2 != 0){
    for (auto x : cnt) {
      if(x.first == 0){
        if(x.second != 1){   
          ans = false;
        }
      }
      else if(x.second != 2){
        ans = false;
      }
    }
  }

  if(ans){
    int64_t s = 1;
    
    for (int i = 0; i < n/2; i++) {
      s *= 2;
      s %= 1000000007;
    }

    
    cout << s << endl;
  }
  else{
    cout << 0 << endl;
  }
  

}
             
 
