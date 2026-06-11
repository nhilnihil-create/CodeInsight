#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, c, k, o, per, bus;
int a[N];

int main() {
    scanf("%d%d%d", &n, &c, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    o = 1, per = a[1], bus = 1;
    for(int i = 2; i <= n; i++) {
        if(o < c && a[i] <= per + k) o++;
        else {
            bus++;
            per = a[i];
            o = 1;
        }
    }
    printf("%d\n", bus);
}