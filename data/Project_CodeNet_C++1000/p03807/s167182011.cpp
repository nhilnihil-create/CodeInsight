#include <iostream>

using namespace std;

int main() {

  int n, odd, p;
  cin >> n;
  for(int i =1;i <= n;i++){
    cin >> p;
    odd += p % 2;
  }
  if(odd % 2 == 0){
    cout << "YES";
  }else{
    cout << "NO";
  }
  return 0;
}
