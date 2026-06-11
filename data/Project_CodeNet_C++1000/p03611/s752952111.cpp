#include<bits/stdc++.h>
using namespace std;
#define MAX_A 100010
int cnt[MAX_A];
int main(void){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        cnt[++a]++;
    }                     //读入数列 
    int ans = 0;
    for (int i = 0; i < MAX_A; i++) {
        int cur = cnt[i - 1] + cnt[i] + cnt[i + 1];
        if (cur > ans) ans = cur;
    }
    printf("%d\n", ans);
    return 0;
}