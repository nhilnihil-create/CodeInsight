#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

constexpr ll mod = 1000000007;

int main() {
    int n;
    scanf("%d",&n);
    vector<int> a(n);
    rep(i,n) scanf("%d",&a[i]);
    sort(a.begin(),a.end());
    vector<int> v;
    if(n % 2 == 1) {
        v.push_back(0);
        for(int i = 2; i < n; i+=2) {
            v.push_back(i);
            v.push_back(i);
        }
        if(v != a) {
            printf("%d\n",0);
            return 0;
        }
        int h = (n-1) / 2;
        ll ans = 1;
        rep(i,h) {
            ans *= 2;
            ans %= mod;
        }
        printf("%ld\n",ans);
        return 0;
    } else {
        for(int i = 1; i < n; i+=2) {
            v.push_back(i);
            v.push_back(i);
        }
        if(v != a) {
            printf("%d\n",0);
            return 0;
        }
        int h = n / 2;
        ll ans = 1;
        rep(i,h) {
            ans *= 2;
            ans %= mod;
        }
        printf("%ld",ans);
        return 0;
    }
}