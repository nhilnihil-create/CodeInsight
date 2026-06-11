#include <iostream>

using namespace std;

const int N = 100010;
typedef long long ll;

int n,m;
int mod = 1e9+7;
int a[N],b[N];

int main()
{
   ll num;
   ll sum1 = 0,sum2 = 0;
   cin >> n >> m;
   for (int i = 1; i <= n; i ++ )
    {
    cin >> num;
    sum1 += (i-1)*num-(n-i)*num;
    sum1 %= mod;
   }
   for (int i = 1; i <= m; i ++ )
   {
    cin >> num;
    sum2 += (i-1)*num-(m-i)*num;
    sum2 %= mod;
   }
   cout << (sum1 * sum2) % mod << endl;
   return 0;
}
