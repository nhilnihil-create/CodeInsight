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
   int a = n % 10;
   int b = n / 100;
   if (a == b)
   {
      cout << "Yes" << endl;
   }
   else
   {
      cout << "No" << endl;
   }
   return 0;
}
