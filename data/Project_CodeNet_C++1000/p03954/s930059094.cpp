#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 1e5 + 9;
int a[N << 1], f[N << 1], n;
bool check(int x){
    int sum = 0;
    for(int i = 1; i < 2*n; i++) f[i] = a[i] >= x, sum += f[i];
    for(int i = n-1; i >= 1; i--){
        int xx = 2*n-i;
        if(f[xx] == f[xx - 1]) return f[xx]; 
        if(f[i] == f[i+1]) return f[i]; 
    }
    return sum >= n;
}
int erfen(int l, int r){
    while(l < r){
        int mid = (l + r + 1) / 2;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i < 2*n; i++) scanf("%d", &a[i]);
    printf("%d", erfen(1, 2*n-1));
    return 0;
}