#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
list <int> ans;
bool vis[50] = {0};
int main()
{
    LL n;
    scanf("%lld" , &n);
    ++n;
    int p = 0 , q = 0;
    while(n)
    {
        vis[p++] = n & 1;
        n >>= 1;
    }
    for(int i = p - 2 ; i >= 0 ; --i)
    {
        ans.push_back(++q);
        if(vis[i])
            ans.push_front(++q);
    }
    printf("%d\n" , q + q);
    for(int i = 1 ; i <= q ; ++i)
        printf("%d " , i);
    for(int i = 1 ; i <= q ; ++i)
    {
        printf("%d" , ans.front());
        putchar(" \n"[i == q + 1]);
        ans.pop_front();
    }
}
