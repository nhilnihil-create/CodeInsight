#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int main()
{
   ll x, a, b;
   cin >> x >> a >> b;
   if (b - a <= 0)
   {
      cout << "delicious" << endl;
   }
   else if (b - a <= x)
   {
      cout << "safe" << endl;
   }
   else
   {
      cout << "dangerous" << endl;
   }
   return 0;
}
