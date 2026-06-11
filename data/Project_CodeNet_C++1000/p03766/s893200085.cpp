#include <iostream>
#define nmax 1000000
#define mod 1000000007
using std::cin;
using std::cout;
int n, f[nmax+nmax+3], fsum[nmax+nmax+3];
int qmod(int x)
{
    return (x < 0) ? x + mod : ((x < mod) ? x : x - mod);
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    if(n == 1){
      cout << 1;
      return 0;
    }
    if(n == 2){
      cout << 4;
      return 0;
    }
    f[n] = n;
    f[n - 1] = (long long) n * n % mod;
    for(int i = n + n + 1; i > n; --i)
      f[i] = 1;
    fsum[n + n + 1] = 1;
    for(int i = n + n; i > n - 2; --i)
      fsum[i] = qmod(fsum[i + 1] + f[i]);
    for(int i = n - 2; i > 0; --i){
      f[i] = qmod(qmod(f[i + 1] + qmod(fsum[i + 3] - fsum[i + n + 2])) + (long long) (n - 1) * (n - 1) % mod);
      fsum[i] = qmod(f[i] + fsum[i + 1]);
    }
    cout << f[1];
    return 0;
}
