#include <iostream>

using namespace std;

#define rep(i, n) for(int i = 1; i <= (n); ++i)

int main(){
  int N, x;
  cin >> N;

  rep(i, N){
    if (i*(i+1)/2 >= N){
      x = i;
      break;
    }
  }
  int y = x*(x+1)/2;
  int dame = y - N;
  rep(i, x){
    if (i == dame){
      continue;
    }
    cout << i << endl;
  }
}