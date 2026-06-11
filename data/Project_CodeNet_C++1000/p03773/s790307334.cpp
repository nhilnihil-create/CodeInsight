#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int main()
{
   int a, b;
   cin >> a >> b;
   if (a + b >= 24)
   {
      cout << a + b - 24 << endl;
   }
   else
   {
      cout << a + b << endl;
   }
   return 0;
}
