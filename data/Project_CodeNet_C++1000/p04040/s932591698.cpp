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
int nxt(){int x;cin >> x;return x;}
int factorial[N], arr[N];
int power(int x, int y){
    if (y == 0)
        return 1;
    int p = power(x, y/2) % 1000000007;
    p = (p * p) % 1000000007;
    return (y%2 == 0)? p : (x * p) % 1000000007;
}
int inv(int a){
	return power(a, 1000000005);
}
int f(int a, int b, int c, int d){
	int x = c - a;
	int y = d - b;
	y = y + x;
	return factorial[y] * arr[x] % 1000000007 * arr[y-x] % 1000000007;
}
int32_t main()
{
    base
    factorial[0] = 1;
	arr[0] = 1;
	for(int i = 1; i < N; i++){
		factorial[i] = (factorial[i-1]*i) % 1000000007;
		arr[i] = inv(factorial[i]);
	}
	int H=nxt(),W=nxt(),h=nxt(),w=nxt();
	int ans = 0;
	for(int i = 0; i < H-h; i++){
		ans += f(0, 0, i, w-1) * f(i, w, H-1, W-1);
		ans %= 1000000007;
	}
	cout << ans;
    exit
}

