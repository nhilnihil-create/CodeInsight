#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,c;
  cin >> N;
  vector<int> vec(N);
  int cnt = 1;
  
  for (int i = 0;i<N;i++){
    int a;
    cin >>a;
    vec.at(i) = a;
    if (vec.at(0) == 2){
      cout << 1 << endl;
      break;
    }
  }
  
  c = vec.at(0);
  
  for (int i = 0;i<N;i++){   
    if (vec.at(0) != 2) {
      if (c != 2){
        cnt++;
        c = vec.at(c-1);
      }
      else if(c == 2){
        cout << cnt << endl;
        break;
      }
      if ( i == N-1 && c != 2){
        cout << -1 << endl;
        break;
      }
    }
  }
  
  
}


