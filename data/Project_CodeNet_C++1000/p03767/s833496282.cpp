#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i,s,n) for(int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(){
   int n;
   cin >> n;
   int a[3 * n];
   rep(i, 3 * n) cin >> a[i];
   sort(a, a + 3 * n);
   ll ans = 0;
   for(int i = n; i < 3 * n;i+=2)
       ans += a[i];
   cout << ans << endl;
   return 0;
}