#include <iostream>
using namespace std;

int main(void){
  int x;
  cin >> x;
  int sum = 0;
  int count = 0;
  while(x > sum){
    count++;
    sum += count;
  }
  cout << count << endl;
  return 0;
}
