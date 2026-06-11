#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int main()
{
   int n;
   cin >> n;
   while (n)
   {
      if (n % 10 == 9)
      {
         cout << "Yes" << endl;
         return 0;
      }
      n /= 10;
   }
   cout << "No" << endl;

   return 0;
}
