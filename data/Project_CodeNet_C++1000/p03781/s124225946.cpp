#include <iostream>
using namespace std;
int main(){
  long int x;
  cin >> x;
  long int count = 0;
  for(int i = 1;;i++){
    count+=i;
    if(count >= x){
      cout << i << endl;
      break;
    }
  }
  return 0;
}