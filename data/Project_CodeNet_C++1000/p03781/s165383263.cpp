#include <iostream>
using namespace std;

int main(){
  int x;
  cin >> x;
  
  int t = 0, count = 0;
  while( t < x ){
    t += count + 1;
    count ++;
  }
  cout << count << endl;
}