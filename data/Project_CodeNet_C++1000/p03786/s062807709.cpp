#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;
const ll inf = 1001001001;
const ll mod = 1000000007;
 
int main() {
 int n;
 cin >> n;
 vector<ll>a(n);
 rep(i, 0, n)cin >> a[i];
 sort(a.begin(), a.end());
 int cnt = 0;
 ll sum = 0; 
 rep(i, 0, n-1){
     sum += a[i];
     if(sum*2 < a[i+1])cnt=i+1;
 }
 cout << n-cnt << endl;
}