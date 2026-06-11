#include <stdio.h>
#include <iostream>
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 100000 + 10;

int n;
int a[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    int pre = 1, used = 0;
    long long ans = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] < pre + 2) {
            ans = ans * (i - used) % mod;
            used++; 
        }
        else {
            pre += 2;
        }
    }
    for (int i = n - used; i > 0; i--) ans = ans * i % mod;
    cout << ans << endl;
    return 0;
}