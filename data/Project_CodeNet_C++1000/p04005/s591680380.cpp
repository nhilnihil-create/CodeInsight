#include <cstdio>

using namespace std;

long long a, b, c, ans[4];

int main()
{
    scanf("%lld%lld%lld", &a, &b, &c);
    ans[1] = (a % 2) ? b * c : 0;
    ans[2] = (b % 2) ? a * c : 0;
    ans[3] = (c % 2) ? a * b : 0;
    if(!ans[1] || !ans[2] || !ans[3])ans[0] = 0;
    else
    {
        ans[0] = ans[1] < ans[2] ? ans[1] : ans[2];
        ans[0] = ans[0] < ans[3] ? ans[0] : ans[3];
    }
    printf("%lld", ans[0]);
}