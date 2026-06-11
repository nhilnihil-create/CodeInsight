#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> l, r;

int main()
{
    cin >> N >> M;
    l.resize(N);
    r.resize(N);
    for (int i=0; i<N; i++) cin >> l[i] >> r[i];

    vector<int> ans(M+1, 0);

    for (int i=0; i<N; i++)
    {
        int l_ = l[i], r_ = r[i];
        int l__ = r_ + 1;
        for (int j=1; j * j<=M; j++)
        {
            if ((l_ + j - 1) / j <= r_ / j)
            {
                ans[(l_ + j - 1)/ j]++;
                ans[min(r_ / j + 1, l__)]--;
                l__ = (l_+j-1)/j;
            }
        }
        for (int m=1; m<l__; m++)
        {
            if ((l_ - 1) / m < r_ / m)
            {
                ans[m]++; ans[m+1]--;
            }
        }
    }
    int ans_ = 0;
    for (int i=1; i<=M; i++)
    {
        ans_ += ans[i];
        cout << ans_ << endl;
    }
}
