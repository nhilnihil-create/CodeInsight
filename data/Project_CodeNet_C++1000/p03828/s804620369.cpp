#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <bitset>
#include <cmath>
#include <stack>
#include <iomanip>
#include <map>
#include <math.h>
#include <list>
#include <deque>
typedef long long ll;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll MOD = 1000000007;
ll INF = 1LL << 60;

ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }
ll LCM(ll a, ll b) {return a / GCD(a, b) * b;}
vector<ll> prime(1001,0);

void prime_fact(ll N)
{
    for(ll a = 2; N >= a * a; a++)
    {
        if(N % a != 0) continue;
        ll ex = 0;
        while(N % a == 0)
        {
            N/= a;
            ex++;
        }
        prime[a] += ex;
    }
    if(N != 1) prime[N] += 1;
    return;
}

int main()
{
    ll N;
    cin >> N;
    for(ll i = 1; i <= N; i++)
    {
        prime_fact(i);
    }
    ll ans = 1;
    for(int i = 0; i < 1001; i++)
    {
        if(prime[i] != 0)
        ans = ans % MOD * (prime[i] + 1) %MOD;
    }
    cout << ans << endl;
}
