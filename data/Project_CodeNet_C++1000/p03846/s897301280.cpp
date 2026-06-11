#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#define ll long long int
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int mx4[] = {0,1,0,-1};
int my4[] = {1,0,-1,0};
const int MOD = 1e9+7;
const int MAX = 510000;

long long fac[MAX], finv[MAX], inv[MAX];

int modPow(long long a, long long n, long long p) {
  if (n == 1) return a % p;
  if (n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;
  long long t = modPow(a, n / 2, p);
  return (t * t) % p;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    if(n == 1 && a[0] == 0){
        cout << 1 << endl;
        return 0;
    }else if(n == 1 && a[0] != 0){
        cout << 0 << endl;
        return 0;
    }

    sort(a.begin(),a.end());
    
    vector<int> b(n);
    for(int i=n-1;i>=0;i-=2){
        b[i] = i;
        b[i-1] = i;
    }
    
    rep(i,n){
        if(a[i] != b[i]){
            cout << 0 << endl;
            return 0;
        }
    }
    
    ll ans = modPow(2,n/2,MOD);
    cout << ans << endl;
}


