#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for (int i = x; i < n; i++)
#define OP(m) cout << m << endl
typedef long long ll;
typedef unsigned long long ull;

bool dp[5001][5001];

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    sort(ALL(a));

    dp[0][0] = 1;
    int left = 0, right = n;
    while (right - left > 0)
    {
        int mid = (right + left) / 2;
        int b[n - 1];
        int m = 0;
        rep(i, n - 1)
        {
            if (m == mid)
            {
                m++;
                i--;
                continue;
            }
            b[i] = a[m];
            m++;
        }
        rep(i, n - 1)
        {
            rep(j, k)
            {
                dp[i + 1][j] = dp[i][j];
                if (j - b[i] >= 0)
                    dp[i + 1][j] = dp[i][j - b[i]] || dp[i][j];
            }
        }
        bool flag = 0;
        rep(j, k)
        {
            if (dp[n - 1][j] == 1 && j + a[mid] >= k)
                flag = 1;
        }
        if (flag == 0)
            left = mid + 1;
        else
            right = mid;
    }
    OP(right);
    return 0;
}

/*
bool dp[5001][5001];

int main()
{
    int n, k;
    cin >> n >> k;
    deque<int> q;
    rep(i, n)
    {
        int a;
        cin >> a;
        q.push_back(a);
    }

    int cnt = 0;
    rep(t, n)
    {
        rep(i, n + 1) rep(j, k + 1) dp[i][j] = 0;
        dp[0][0] = 1;
        q.push_back(q.front());
        q.pop_front();
        rep(i, n - 1)
        {
            rep(j, k)
            {
                dp[i + 1][j] = dp[i][j];
                if (j - q[i] >= 0)
                    dp[i + 1][j] = dp[i][j - q[i]] || dp[i][j];
            }
        }

        bool flag = 0;
        rep(j, k)
        {
            if (dp[n - 1][j] == 1 && j + q.back() >= k)
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
            cnt++;
    }
    OP(cnt);

    return 0;
}*/