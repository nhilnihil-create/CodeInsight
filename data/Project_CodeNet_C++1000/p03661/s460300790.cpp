#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;
int64_t large = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int64_t N, tmp;
    cin >> N;
    vector<int64_t> list(N + 1);
    int64_t sum = 0;
    for (int i = 1; i < N + 1; i++)
    {
        cin >> tmp;
        list[i] = list[i - 1] + tmp;
        sum += tmp;
    }
    int64_t ans = large;
    for (int i = 1; i < N; i++)
    {
        tmp = sum - list[i];
        ans = min(ans, abs(tmp-list[i]));
    }
    cout << ans;
}