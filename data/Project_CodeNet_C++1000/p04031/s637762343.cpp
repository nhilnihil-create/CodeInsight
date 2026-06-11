#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
using P = pair <int, int>;
 

int main() {
   int n;
   cin >> n;
   vector<int> a(n);
   rep(i,n) cin >> a[i];

   int sum = 0;
   rep(i,n){
       sum += a[i];
   }
   int av1 = sum/n;
   int av2 = sum/n+1;

   int ans1=0,ans2=0 ;
   rep(i,n){
       ans1 +=(av1-a[i])*(av1-a[i]);
       ans2 +=(av2-a[i])*(av2-a[i]);

   }
   cout << min (ans1,ans2) <<endl;
}