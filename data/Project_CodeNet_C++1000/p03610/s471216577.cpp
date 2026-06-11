#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;
  int length = S.size(),size;
  if(length%2 ==0){
    size = length/2;
  }else{
    size = length/2+1;
  }
  string ans(size, '0');
  int plus = 0;
  for(int i=0; i<size; i++){
    ans.at(i) = S.at(i+plus);
    plus++;
  }
  cout << ans << endl;
}