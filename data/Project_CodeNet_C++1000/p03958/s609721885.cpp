#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;
typedef pair<int, int> P;

int k, t;

int main()
{
    cin >> k >> t;
    priority_queue<P> que;
    rep(i, t)
    {
        int a;
        cin >> a;
        que.push(P(a, i));
    }
    int res = 0;
    int p = -1;
    while(que.size())
    {
        auto a = que.top();
        que.pop();
        if(a.second == p)
        {
            if(que.size() == 0)
            {
                res += a.first;
                break;
            }
            auto b = que.top();
            que.pop();
            p = b.second;
            b.first--;
            que.push(a);
            if(b.first) que.push(b);
        }
        else
        {
            p = a.second;
            a.first--;
            if(a.first) que.push(a);
        }
    }

    cout << res << endl;

    return 0;
}