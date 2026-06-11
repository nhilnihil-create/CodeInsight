#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
int num[MAXN];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d",&a);
        num[a++]++; 
    }
    int ans = 0;
    for (int i = 0; i < MAXN; i++) {
        int maxsum = num[i - 1] + num[i] + num[i + 1]; // add ,sub ,do not ,最大化 
        if (maxsum > ans) {
			ans = maxsum;
		} 
    }
    printf("%d\n", ans);
    return 0;
}