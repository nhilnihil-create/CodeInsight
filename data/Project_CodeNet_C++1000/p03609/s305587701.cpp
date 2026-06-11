#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int main()
{
   int x, t;
   cin >> x >> t;

   if (x >= t)
   {
      cout << x - t << endl;
   }
   else
   {
      cout << 0 << endl;
   }
   return 0;
}
