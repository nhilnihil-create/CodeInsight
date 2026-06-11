#include <string>
#include <math.h>
#include <iostream>

using namespace std;

int main()
{
  string s;
  cin >> s;
  int sum = 0;
  if (s[0] == 'C')
    sum = sum + 1;
  if (s[1] == 'O')
    sum = sum + 1;
  if (s[2] == 'D')
    sum = sum + 1;
  if (s[3] == 'E')
    sum = sum + 1;
  if (s[4] == 'F')
    sum = sum + 1;
  if (s[5] == 'E')
    sum = sum + 1;
  if (s[6] == 'S')
    sum = sum + 1;
  if (s[7] == 'T')
    sum = sum + 1;
  if (s[8] == 'I')
    sum = sum + 1;
  if (s[9] == 'V')
    sum = sum + 1;
  if (s[10] == 'A')
    sum = sum + 1;
  if (s[11] == 'L')
    sum = sum + 1;
  if (s[12] == '2')
    sum = sum + 1;
  if (s[13] == '0')
    sum = sum + 1;
  if (s[14] == '1')
    sum = sum + 1;
  if (s[15] == '6')
    sum = sum + 1;
  cout << 16 - sum;
}