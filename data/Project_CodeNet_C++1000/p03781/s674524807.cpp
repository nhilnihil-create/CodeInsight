#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  int ans =0;
  for(int i =1;;i++){
    ans +=i;
    if( ans >=n){
      cout << i;
      return 0;
  }
  }
}
