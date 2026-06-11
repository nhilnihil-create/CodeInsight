#include <iostream>
using namespace std;
int main(){
  int N;
  cin >> N;
  int t = 1, s = 0;
  for(int i = 1; i <= N; ++i){
    s += i;
    if(s >= N){
      t = i;
      break;
    }
  }
  for(int i = 1; i <= t; ++i){
    if(i != s - N) cout << i << endl;
  }
  return 0;
}
