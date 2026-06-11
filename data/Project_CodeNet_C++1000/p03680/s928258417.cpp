#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  
  for (int i = 0; i < N; i++){
    cin >> vec.at(i) ;
  }
  
   int a = 1;
   int x = 0;
    
  for (int j = 0; j < N; j++){
    
    a = vec.at(a - 1);
    
    x += 1;
    
    if (a == 2){
      cout << x << endl;
      break;
    }
    
    else if (a != 2 && j == N - 1){
      cout << -1 << endl;
    }
  }
}
 