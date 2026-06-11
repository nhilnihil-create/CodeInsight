//#define _GLIBCXX_DEBUG
#include "bits/stdc++.h"

using namespace std;

//------------------------------- Type Names -------------------------------//

using i64 = int_fast64_t;

using seika = string;
//{akari : 1D, yukari : 2D, maki : 3D} vector
template <class kizuna>
using akari = vector<kizuna>;
template <class yuzuki>
using yukari = akari<akari<yuzuki>>;
template <class tsurumaki>
using maki = akari<yukari<tsurumaki>>;
//{akane : ascending order, aoi : decending order} priority queue
template <class kotonoha>
using akane = priority_queue<kotonoha, akari<kotonoha>, greater<kotonoha>>;
template <class kotonoha>
using aoi = priority_queue<kotonoha>;

//------------------------------- Libraries ---------------------------------//

//------------------------------- Dubug Functions ---------------------------//
inline void print()
{
    cout << endl;
}
template <typename First, typename... Rest>
void print(const First &first, const Rest &... rest)
{
    cout << first << ' ';
    print(rest...);
}
//------------------------------- Solver ------------------------------------//

void solve()
{
    seika s;
    cin >> s;
    int n = s.size();
    akari<int> from(26, n + 1);
    yukari<pair<int, char>> es(n + 2);
    for (int i = n; i >= 0; i--)
    {
        for (int j = 0; j < 26; j++)
        {
            es[from[j]].emplace_back(i, char('a' + j));
        }
        if (i)
        {
            from[s[i - 1] - 'a'] = i;
        }
    }
    akari<int> nxt(n + 2, -1), lastChar(n + 2, '~'), dist(n + 2, 1e9);
    queue<int> q;
    q.push(n + 1);
    dist[n + 1] = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto &e : es[v])
        {
            int pv = e.first;
            char pc = e.second;
            if (dist[pv] == dist[v] + 1)
            {
                if (pc < lastChar[pv])
                {
                    lastChar[pv] = pc;
                    nxt[pv] = v;
                    q.push(pv);
                }
            }
            else if (dist[pv] > dist[v] + 1)
            {
                dist[pv] = dist[v] + 1;
                lastChar[pv] = pc;
                nxt[pv] = v;
                q.push(pv);
            }
        }
    }
    seika ans;
    int cur = 0;
    while (cur <= n)
    {
        ans.push_back(lastChar[cur]);
        cur = nxt[cur];
        //print(cur, ans);
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}
