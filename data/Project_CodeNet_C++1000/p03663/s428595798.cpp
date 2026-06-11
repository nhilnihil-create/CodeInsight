#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long int64;
 
int cmp(int64 a, int64 b)
{
  string x = to_string(a);
  string y = to_string(b);
  return a <= b && x <= y || a > b && x > y;
}

int64 dest;
int main()
{
  //cin >> dest;
  const int l = 9;
  int64 a = 1, b = 9;
  for (int i = 1; i < l; ++i) a *= 10, b = b * 10 + 9;
  const int64 maxv = b;
  while (a <= b)
  {
    int64 mid = a + b >> 1;
    printf("? %lld0\n", mid); /*puts(cmp(mid, 123) ? "Y" : "N");*/ fflush(stdout);
    char buff[32];
    scanf("%s", buff);
    //buff[0] = cmp(mid, dest) ? 'Y' : 'N';
    if (buff[0] == 'Y') b = mid - 1; else a = mid + 1;
  }
  vector<int64> tester;
  int64 aa = a;
  while (aa%10==0) aa /= 10;
  for (int64 x = aa*10; x <= maxv; x = x * 10) tester.push_back(x+9);
  if (aa%10>1)
  {
    tester.push_back(aa-1);
    for (int64 x = (aa-1)*10; x <= maxv; x = x * 10) tester.push_back(x+9);
  }
  if (aa%10<9)
  {
    tester.push_back(aa+1);
    for (int64 x = (aa+1)*10; x <= maxv; x = x * 10) tester.push_back(x+9);
  }
  string s;
  for (auto& iter: tester)
  {
    printf("? %lld\n", iter); /*puts(cmp(iter, 123) ? "Y" : "N");*/ fflush(stdout);
    char buff[32];
    scanf("%s", buff);
    //buff[0] = cmp(iter, dest) ? 'Y' : 'N';
    s += buff[0] == 'Y' ? '1' : '0';
  }
  for (;;)
  {
    string me;
    for (auto& iter: tester)
      me += cmp(iter, aa) ? '1' : '0';
    if (me == s) {printf("! %lld\n", aa); break;}
    aa *= 10;
  }
  return 0;
}