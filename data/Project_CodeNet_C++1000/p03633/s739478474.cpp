#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

long long gcd2(long long x,long long y) {
    if(y == 0) return x;
    return gcd2(y,x % y);
}

long long lcm2(long long x,long long y) {
    return x / gcd2(x,y) * y;
}

long long lcm(vector<long long> a) {
    long long ans = a[0];
    for(long long i = 1; i < a.size(); i++) {
      ans = lcm2(ans,a[i]);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) {
        cin >> a[i];
    }
    cout << lcm(a) << endl;
    return 0;
}