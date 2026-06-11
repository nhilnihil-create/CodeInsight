#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define ep emplace_back
#define st first
#define sc second

using namespace std;

const ll mod = 1e9 + 7;
const int e = 1e6 + 69;
const int base = 311;

// dung inverse module de tinh kCn
// 3
// cach tao hoan vi tu n so : n*(n+1)/2;

ll gt[e];
int a, b, n;


int main()
{
   ll n, m;
   cin >> n >> m;
   if(abs(n - m) > 1)
   {
       cout << 0;
       return 0;
   }
   gt[0] = 1;
   for(int i=1; i<=max(n, m); i++) gt[i] = (gt[i-1]*i%mod)%mod;
   if(n != m)
   {
       cout << (gt[n]%mod*gt[m]%mod)%mod;
   }
   else
   {
       cout << 2*(gt[n]%mod*gt[m]%mod)%mod;
   }
}
