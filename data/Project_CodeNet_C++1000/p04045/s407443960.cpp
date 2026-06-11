#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;
 
int main() {
 int n, k;
 cin >> n >> k;
 vector<int>a(k);
 rep(i, 0, k)cin >> a[i];
 rep(i, 0, 100000){
     int tempn = n+ i;
     string temps = to_string(tempn);
     int m = temps.size();
     int cnt = 0;
     rep(j, 0, m){
         rep(l, 0, k){
             if(temps[j]-'0'== a[l])cnt++;
        }
     }
     if(cnt == 0){
         cout << temps << endl;
         return 0;
     }
    }
}