#include <iostream>

using namespace std;

int main(){
  int n, k, x, y;
  cin >> n >> k >> x >> y;
  
  int result = 0;
  if(n - k >= 0){
    result += k * x;
    result += (n - k) * y;
  }
  else{
    result += n * x;
  }
  
  cout << result << endl;
}