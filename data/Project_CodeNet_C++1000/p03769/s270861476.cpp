#include <bits/stdc++.h>

using namespace std;

//#define FILE_IO

typedef long long LL;

LL N;
LL dp[205][2];
LL cnt[205];
vector <int> ans;

void solve(LL N)
{
    if(N == 1)  return;
    if(N == 2)  { ans.push_back(1); return; }

    if(N % 2 == 1)
    {
        solve(N - 1);
        int val = ans.size() + 1;
        ans.insert(ans.begin(), val);
    }
    else
    {
        solve(N / 2);
        int val = ans.size() + 1;
        ans.push_back(val);
    }
}

int main()
{
    #ifdef FILE_IO
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    scanf("%lld", &N);
    solve(N + 1);

    printf("%d\n", 2 * ans.size());
    for(auto x: ans)
        printf("%d ", x);
    for(int i = 1; i <= ans.size(); i++)
        printf("%d ", i);

    return 0;
}
