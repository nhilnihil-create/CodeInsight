#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 5;

int n;
ll sum;
int a[N];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= 3 * n; i++) {
        scanf("%d", &a[i]);
        a[i] *= -1;
    }
    sort(a + 1, a + (3 * n) + 1);
    for(int i = 1; i <= (3 * n); i++) {
        a[i] *= -1;
    }
    sum = 0;
    for(int i = 2; i <= (2 * n); i += 2) {
        sum += a[i];
    }
    printf("%lld\n", sum);
}