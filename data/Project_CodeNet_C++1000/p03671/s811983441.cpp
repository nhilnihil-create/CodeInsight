#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  vector <int> bell(3);
  cin >> bell[0] >> bell[1] >> bell[2];
  sort(bell.begin(), bell.end());
  cout << bell[0]+bell[1] << endl;
  return 0;
}
