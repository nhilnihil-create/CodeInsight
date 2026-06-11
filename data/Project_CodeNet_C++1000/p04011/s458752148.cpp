#include <iostream>

using namespace std;

int main(){
  int n, k, x, y;
  cin >> n >> k >> x >> y;

  int total = 0;
  if(n <= k){
    total = n*x;
  } else {
    total = k*x + (n-k)*y;
  }
  cout << total << endl;
  return 0;
}