#include <iostream>
#include <string>
using namespace std;
int main()
{
  int H, W;
  cin >> H >> W;
  for (int w = 0; w <= W+1; w++) cout << "#";
  cout << endl;
  for (int h = 0; h < H; h++) {
    cout << "#";
    string a;
    cin >> a;
    cout << a << "#" << endl;
  }
  for (int w = 0; w <= W+1; w++) cout << "#";
  cout << endl;
  return 0;
}
