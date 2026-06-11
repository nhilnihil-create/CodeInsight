#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int main()
{
   vector<int> a(3);

   cin >> a[0] >> a[1] >> a[2];

   sort(a.begin(), a.end());
   cout << a[0] + a[1] << endl;

   return 0;
}
