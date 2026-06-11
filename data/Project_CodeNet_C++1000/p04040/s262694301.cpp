#include<bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;

int n , m , a , b;
typedef long long ll;

int fac[maxn * 2];

int Pow(int a , int b)
{
    if(b == 0)return 1;
    int r = Pow(a , b / 2);
    if(b & 1)return (ll)r * r % mod * a % mod;
    return (ll)r * r % mod;
}

int C(int n , int k)
{
    if(k > n)return 0;
    return (ll)fac[n] * Pow((ll)fac[k]*fac[n-k] % mod,mod-2) % mod;
}

int main(){
    cin >> m >> n >> a >> b;
    fac[0] = 1;
    for(int i = 1 ; i <= 2e5 ; ++i)fac[i] = (ll)fac[i - 1] * i % mod;
    int res = 0;
    for(int i = b + 1 ; i <= n ; ++i)
    {
        res += (ll)C(i + m - a - 2 , i - 1) * C(a - 1 + n - i , n - i) % mod;
        if(res >= mod)res -= mod;
//        cout << res << endl;
    }
    cout << res;
}
