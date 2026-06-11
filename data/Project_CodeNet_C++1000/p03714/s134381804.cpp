#include <bits/stdc++.h>
#define dbg(x) cerr << #x << " = " << x << endl
#define all(x) begin(x), end(x)
#define _ << ' ' <<
using namespace std;
using ll = long long;

int a[300000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < 3 * n; ++i)
        cin >> a[i];

    multiset<int> s3, s4;
    priority_queue<int, vector<int>, greater<int>> s1;
    ll lsum = 0, rsum = 0;
    for (int i = 0; i < n; ++i)
    {
        lsum += a[i];
        s1.push(a[i]);
    }

    for (int i = n; i < 3 * n; ++i)
    {
        if (s3.size() < n)
        {
            rsum += a[i];
            s3.insert(a[i]);
        }
        else if (a[i] < *s3.rbegin())
        {
            int x = *s3.rbegin();
            s3.erase(s3.find(x));
            s4.insert(x);
            s3.insert(a[i]);
            rsum -= x;
            rsum += a[i];
        }
        else
        {
            s4.insert(a[i]);
        }
    }
    ll sol = lsum - rsum;
    for (int i = n; i < 2 * n; ++i)
    {
        if (a[i] > s1.top())
        {
            lsum -= s1.top();
            s1.pop();
            s1.push(a[i]);
            lsum += a[i];
        }
        auto it = s3.find(a[i]);
        if (it != s3.end())
        {
            s3.erase(it);
            rsum -= a[i];
            rsum += *s4.begin();
            s3.insert(*s4.begin());
            s4.erase(s4.begin());
        }
        else
            s4.erase(s4.find(a[i]));

        sol = max(sol, lsum - rsum);
    }
    cout << sol;
}
