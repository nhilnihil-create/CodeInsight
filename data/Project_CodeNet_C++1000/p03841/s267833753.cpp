#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
ll INF = 1e9+7;
int main()
{
    int n;
    cin >> n;
    vector<P> x(n);
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        x[i] = P(a, i+1);
    }
    sort(x.begin(), x.end());

    set<int> s;
    for(int i = 1; i <= n*n; i++)
    {
        s.insert(i);
    }

    vector<int> ans(n*n+1);
    vector<P> v(n);
    for(int i = 0; i < n; i++)
    {
        P p = x[i];
        int now = p.first;
        int num = p.second;
        int l = num-1;
        int r = n-num;
        while(l--)
        {
            int tmp = *s.begin();
            if(tmp >= now)
            {
                cout << "No" << endl;
                return 0;
            }
            ans[tmp] = num;
            s.erase(tmp);
        }
        if(s.find(now) == s.end())
        {
          cout << "No" << endl;
          return 0;
        }
        ans[now] = num;
        s.erase(now);
        v[i] = P(r, num);
    }
    for(int i = 0; i < n; i++)
    {
        P p = v[i];
        int now = x[i].first;
        for(int j = 0; j < p.first; j++)
        {
            int tmp = *s.begin();
            if(tmp < x[i].first)
            {
                cout << "No" << endl;
                return 0;
            }
            ans[tmp] = p.second;
            s.erase(tmp);
        }
    }
    cout << "Yes" << endl;
    for(int i = 1; i <= n*n; i++)
    {
        cout << ans[i] << " ";
    }
}