#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int K, T;
    cin >> K >> T;
    vector<int> as(T);
    for(int i=0; i<T; i++) cin >> as.at(i);

    priority_queue<pair<int, int>> q;
    for(int i=0; i<T; i++)
    {
        q.push(make_pair(as.at(i), i));
    }

    int prei = -1;
    int ans = 0;
    while(!q.empty())
    {
        pair<int, int> p = q.top();
        q.pop();
        pair<int, int> temp = p;
        if(!q.empty() && p.second == prei)
        {
            p = q.top();
            q.pop();
            q.push(temp);
        }
        if(p.second == prei) ans++;
        p.first--;
        prei = p.second;
        if(p.first != 0) q.push(p);
    }
    cout << ans << '\n';

    return 0;
}
