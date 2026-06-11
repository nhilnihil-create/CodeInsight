#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; 
  string prefix,suffix;
  cin >> N >> prefix >> suffix;

  int len_common= N;
  while(len_common > 0){
    bool is_satisfied= true;
    int offset= N- len_common;
    for(int i=0; i<len_common; i++){
      if(prefix.at(offset+ i) != suffix.at(i)){
        is_satisfied= false;
        break;
      }
    }
    if(is_satisfied){ break; }

    len_common--;
  }

  int ans= 2*N- len_common;

  cout << ans << endl;
}