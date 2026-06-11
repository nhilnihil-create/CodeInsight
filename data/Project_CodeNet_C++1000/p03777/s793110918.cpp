#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int main()
{
   char a, b;
   cin >> a >> b;
   if ((a == 'H' && b == 'H') || (a == 'D' && b == 'D'))
   {
      cout << "H" << endl;
   }
   else
   {
      cout << "D" << endl;
   }
   return 0;
}
