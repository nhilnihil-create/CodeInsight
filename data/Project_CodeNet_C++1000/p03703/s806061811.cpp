#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>


using namespace std;

long long n, k;
long long a[500000];

long long solve(int l, int r)
{
    if (l + 1 == r)
    {
        if (a[l] < 0) return 0;
        return 1;
    }
    int m = (l + r) / 2;
    long long res = solve(l, m) + solve(m, r);
    vector<long long> s, p;
    long long counter = 0;
    for (int i = m - 1; i >= l; i--)
    {
        counter += a[i];
        s.push_back(counter);
    }
    counter = 0;
    for (int i = m; i < r; i++)
    {
        counter += a[i];
        p.push_back(counter);
    }
    sort(s.begin(), s.end());
    sort(p.begin(), p.end());
    int pointer = s.size() - 1;
    int cnt = 0;
    for (int i = 0; i < p.size(); i++)
    {
        long long d = p[i];
        // s[j] >= -d
        while (pointer >= 0 && s[pointer] >= -d)
        {
            cnt++;
            pointer--;
        }
        res += cnt;
    }
    return res;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] -= k;
    }
    cout << solve(0, n);
}
