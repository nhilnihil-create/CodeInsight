#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int>vec(N, 0);
  for (int i=0; i < N; i++){
    cin >> vec.at(i);
  }
  int a = 1;
  int x = 0;
  while(x < N ){
    if (a == 2){
    cout << x << endl;
      break;
    }else{
     a = vec.at(a-1);
      x++;
    }
  }
  if (x > N-1){
    cout << "-1" << endl;
  }
}
 