#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  int ans = 1;
  for(int i = 1; 2*i <= N; ){
    i *= 2;
    ans = i;
  }
  cout << ans;
  return 0;
}