#include <iostream>

using namespace std;

int main(){
  int n;
  int seq = 0;
  int result = 0;
  
  cin >> n;
  for (int i = 1;i<=n;i++) {
    int p;
    cin >> p;
    if (i == p) {
      seq++;
    } else {
      if (seq % 2 == 0) {
	result += seq / 2;
      } else {
	result += seq / 2 + 1;
      }
      seq = 0;
    }
  }
  if (seq % 2 == 0) {
    result += seq / 2;
  } else {
    result += seq / 2 + 1;
  }
  cout << result << endl;
  return(0);
}
