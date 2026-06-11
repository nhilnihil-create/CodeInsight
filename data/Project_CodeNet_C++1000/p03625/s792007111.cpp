#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

unsigned long long int ans=1;

int main()
{
    int n, c = 0;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a+n);
    for (int i = n-2, j = n-1; i >= 0 && c < 2; i--, j--) {
        if (a[i] == a[j]) {
            ans *= a[i];
            i--;
            j--;
            c++;
        }
    }
    if (c == 2) cout << ans << endl;
    else printf("0\n");
    return 0;
}