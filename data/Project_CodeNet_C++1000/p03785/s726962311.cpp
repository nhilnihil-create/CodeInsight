#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int main()
{
    int n, c, k;
    cin >> n >> c >> k;
    priority_queue<int, vector<int>, greater<int>> pque;
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        pque.push(t);
    }
    int ans = 0;
    while(!pque.empty())
    {
        int t = pque.top() + k;
        pque.pop();
        int cnt = 1;
        while(!pque.empty() && pque.top() <= t && cnt < c)
        {
            pque.pop();
            cnt++;
        }
        ans++;
    }
    cout << ans << endl;
}
