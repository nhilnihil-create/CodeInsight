#include <iostream>
using namespace std;

int main(void){
  int n;
  cin >> n;

  long long int i = 0, ans = 0;
  for(i = 0; ans < n; i++){ ans += i; }

  for(int j = 1; j < i; j++){
    if(j != (ans - n)){
      cout << j << endl;
    }
  }
  
  return 0;
}
