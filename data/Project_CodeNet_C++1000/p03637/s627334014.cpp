#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  int N;
  cin >> N;
  int mul[3] = {0}; // 2の倍数でない、2の倍数の数、4の倍数の数
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    if ((a&0x03)==0x00) mul[2]++;
    else if ((a&0x01)==0x00) mul[1]++;
    else mul[0]++;
  }

  if (mul[1]==0) {
    if ((mul[0]-1) <= mul[2]) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  else {
    if ((mul[0]) <= mul[2]) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
