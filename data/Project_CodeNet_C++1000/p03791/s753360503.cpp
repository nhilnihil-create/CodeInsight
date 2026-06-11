#include<cstdio>
#include<iostream>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main()
{
    int n, x, k = 0;
    ll ans = 1;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &x);
        k++;
        if(x < 2 * k - 1)
        {
            ans = ans * k % MOD;
            k--;
        }
    }
    for(int i = 2; i <= k; i++)
        ans = ans * i % MOD;
    printf("%d\n", (int)ans);
    return 0;
}