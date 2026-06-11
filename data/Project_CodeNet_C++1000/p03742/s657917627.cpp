#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define pp pair<int,int>
#define ll long long
#define ld long double
int inf=100000000;
ll INF=4000000000000000000;
ll MOD=1000000007;



int main() {
   ll a,b;
   cin >> a >> b;
   ll n,m;
   n=max(a,b);
   m=min(a,b);
   if (n-m>1) cout << "Alice" << endl;
   else cout << "Brown" << endl;

  }