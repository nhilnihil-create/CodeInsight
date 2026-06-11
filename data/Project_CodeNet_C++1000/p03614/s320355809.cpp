#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, a[N], r;

int main(){
    scanf("%d", &n);
    for(int i = 1, x; i <= n; i++){
        scanf("%d", &x);
        a[i] = (x == i);
    }
    for(int i = 1; i <= n; i++){
        if(a[i]){ r++; a[i] = a[i + 1] = 0; }
    }
    printf("%d\n", r);
}