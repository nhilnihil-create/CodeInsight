#include<bits/stdc++.h>
#include <unordered_map>
#define int long long int
#define double long double
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
#define sp(x)   setprecision(x)
#define ceil(a,b)   (a+(b-1))/b
#define LCM(a,b)    (a*b)/__gcd(a,b)
#define all(v)  v.begin(),v.end()
#define alls(s,v)  s.begin(),s.end(),v
#define gena(arr,n,nxt)  generate(arr,arr+n, nxt)
#define genv(v,nxt)  generate(v.begin(),v.end(), nxt)
#define base ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define exit return 0;
using namespace std;
const int N=1000000;
bool prime[N];
void sieve()
{
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<100000000; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*p; i<100000; i += p)
                prime[i] = false;
        }
    }
}
int power(int x, int y)
{
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = res * x;
        y = y >> 1;
        x = x*x;
    }
    return res;
}
int nxt()
{
    int x;
    cin >> x;
    return x;
}
int findTileCount(int x, int y, int l, int r)
{
    int lcm = (x * y) / __gcd(x, y);
    int countl = (l - 1) / lcm;
    int countr = r / lcm;
    return countr - countl;
}
int32_t main()
{
    base
    int n=nxt();
    cout<<(n*(n+1))/2;
    exit
}

