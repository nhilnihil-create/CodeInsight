#include <iostream>
using namespace std;

int main(){
  int abc[3];
  cin >> abc[0] >> abc[1] >> abc[2];
  
  int count5 = 0;
  int count7 = 0;
  for(int num : abc){
    if(num == 5) count5++;
    else if(num == 7) count7++;
  }
  string result = (count5 == 2 && count7 == 1)? "YES" : "NO";

  cout << result;
  return 0;
}