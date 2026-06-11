#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b; scanf("%d%d%d", &n, &a, &b);
    long long ret;
         if (a>b)          {ret = 0;}
    else if (a!=b && n==1) {ret = 0;}
    else if (a==b && n==1) {ret = 1;}
    else                   {ret = (long long)(b-a)*(n-2)+1;}
    printf("%lld\n", ret);
    return 0;
}