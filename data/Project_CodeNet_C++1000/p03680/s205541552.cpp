#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vc(n);
  vector<bool> is_push(n, false);
  int count = 0;
  
  for(int i=0; i<n; i++){
    cin >> vc[i];
  }
  
  
  int pre_b = vc[0];
  is_push[0] = true;
  count += 1;
  int b;
  do{
    if(pre_b == 2){
      cout << count << endl;
      return 0;
    } else{
      b = vc[pre_b-1];
      count += 1;
      is_push[pre_b-1] = true;
      pre_b = b;
    }
  }while(!is_push[b-1]);
  cout << -1 << endl;
  
  return 0;
}