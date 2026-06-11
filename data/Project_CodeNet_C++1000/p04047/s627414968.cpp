#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, l[1000], i, j, sum=0;
    scanf("%d", &n);
    for(i=1;i<=2*n;i++)
        scanf("%d", &l[i]);
    sort(l+1, l+2*n+1);
    for(i=1;i<=n;i++)
        sum+=l[2*i-1];
    printf("%d", sum);
    
    
    return 0;
}