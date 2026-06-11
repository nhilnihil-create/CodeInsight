#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<long long>
#define inf 1000000100
#define infll 1LL << 50

int main()
{
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, ll>> edge;
    vll dist(n+1);
    while(m--)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        edge.pb(make_tuple(a, b, -c));
    }
    dist[1] = 0;
    for(int i = 2; i <= n; i++)
    {
        dist[i] = infll;
    }

    for(int i = 0; i < n; i++)
    {
        for(auto e: edge)
        {
            int aa, bb;
            ll cc;
            tie(aa, bb, cc) = e;
            if(dist[aa] == infll)
            {
                continue;
            }

            if(dist[aa] + cc < dist[bb])
            {
                dist[bb] = dist[aa] + cc;
            }
        }

    }
    vi negative(n+1);
    for(int i = 0; i < n; i++)
    {
        for(auto e: edge)
        {
            int aa, bb;
            ll cc;
            tie(aa, bb, cc) = e;
            if(dist[aa] == infll)
            {
                continue;
            }
            if(dist[aa]+cc < dist[bb])
            {
                negative[aa] = 1;
            }
            if(negative[aa])
            {
                negative[bb] = 1;
            }
        }
    }

    if(!negative[n])
    {
        cout << -dist[n] << endl;
    }
    else
    {
        cout << "inf" << endl;
    }

}