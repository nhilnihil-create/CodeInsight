#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <cstdio>

using namespace std;
#define prev prev55

long long n, m;
int a[500000];
int cnt[500000];
int amount[500000];
vector<int> nums[500000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i], cnt[a[i] % m]++, amount[a[i]]++, nums[a[i] % m].push_back(a[i]);
    int ans = 0;
    for (int i = 0; i <= m - i; i++)
    {
        if (i == (m - i) % m)
        {
            ans += cnt[i] / 2;
        }
        else
        {
            ans += min(cnt[i], cnt[m - i]);
            if (cnt[i] < cnt[m - i])
                swap(nums[i], nums[m - i]), swap(cnt[i], cnt[m - i]);
            int canw = 0;
            for (int j = 0; j < nums[i].size(); j++)
            {
                if (amount[nums[i][j]] % 2 == 1) canw++, amount[nums[i][j]]--;
            }
            int need = cnt[m - i] - canw;
            if (need <= 0)
            {
                for (int j = 0; j < nums[i].size(); j++) ans += amount[nums[i][j]] / 2, amount[nums[i][j]] = 0;
            }
            else
            {
                for (int j = 0; j < nums[i].size(); j++)
                {
                    while (need > 0 && amount[nums[i][j]] > 0)
                    {
                        need -= 2, amount[nums[i][j]] -= 2;
                    }
                    ans += amount[nums[i][j]] / 2, amount[nums[i][j]] = 0;
                }
            }
        }
    }
    cout << ans;
}
