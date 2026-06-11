#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, t;
    scanf("%d %d", &x, &t);
    int ans = x - t;
    if(ans > 0) printf("%d\n", ans);
    else printf("0\n"); 
    return 0;
}