#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<string>
#include<sstream>
#include<cctype>
#include<map>
#include<stack>
#include<queue>
#include<cstdlib>
#include<ctime>
using namespace std;
#define INF 0x3f3f3f3f
typedef long long ll;
int gcd(int a, int b){return b==0?a:gcd(b,a%b);}

const int MOD = 1e9 + 7;

int main()
{
//    freopen("input1.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
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