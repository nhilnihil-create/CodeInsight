#include <bits/stdc++.h>
using namespace std;

int n, odd;
int a[100005];

int main() {
    scanf("%d", &n);
    odd = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if(a[i] & 1) odd++;
    }
    if(odd % 2 == 0) printf("YES\n");
    else printf("NO\n");
}