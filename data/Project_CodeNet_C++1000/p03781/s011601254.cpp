#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, sum = 0, ans = 0;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        ans++;
        sum += i;
        if(sum >= n) break;
    }
    printf("%d\n", ans);
}