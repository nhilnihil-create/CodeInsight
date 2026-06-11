//#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[100009], b[100009];

int main(){
    int n, k, mask;
    scanf("%d %d",&n, &k);    
    for(int i = 0; i < n; i++){
        scanf("%d %d", a+i, b+i);
    }
    k++;
    long long ans = 0;
    for(int bit = 30; bit >= 0; bit--){
        if((k >> bit) & 1){
            mask = k ^ (1<<bit);
            mask |= (1<<bit) - 1;
            long long cur = 0;
            for(int i = 0; i < n; i++){
                if((a[i] & mask) == a[i]){
                    cur += b[i];
                }
            }
            ans = max(ans, cur);
        }
    }
    printf("%lld\n", ans);
    return 0;
}