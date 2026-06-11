#include <iostream>
using namespace std;

int main() {
  int group, sum, stanum, endnum;
  cin >> group;
  for(int i =0; i < group; i++){
    cin >> stanum >> endnum;
    sum += endnum - stanum +1;
  }
  cout << sum << endl;
	
}