#include <cstdio>
#include <iostream>
#define ll long long
using namespace std;
ll a[100000], cnt;
int main() {
    ll n, x;
    cin >> n >> x;
    for(int i=0; i<n; i++) {
        scanf("%lld", &a[i]);
    }
    for(int i=0; i<n - 1; i++) {
        if(a[i] + a[i + 1] > x) {
            cnt += a[i] + a[i + 1] - x;
            if(a[i] <= x) a[i + 1] = x - a[i];
            else {
                a[i + 1] = 0;
                a[i] = x;
            }
        }
    }
    printf("%lld\n", cnt);
    return 0;
}