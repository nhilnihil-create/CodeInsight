#include <bits/stdc++.h>
typedef long long int ll;

typedef std::pair<ll, int> P;

using namespace std;

ll INF = 1e18;

bool bell(vector<ll> &cost, vector<vector<P>> &E)
{
    bool update = true;

    int N = E.size();

    vector<int> visit(0);

    visit.push_back(0);

    cost[0] = 0;

    int count = 0;

    while (update)
    {
        update = false;

        for (int v : visit)
        {

            for (P e : E[v])
            {

                if (cost[e.second] == -INF)
                {

                    visit.push_back(e.second);
                }

                

                if (cost[e.second] < cost[v] + e.first)
                {
                    update = true;

                    cost[e.second] = cost[v] + e.first;

                    if (e.second == N - 1 && count > N)
                    {

                        return 0;
                    }
                }
            }
        }

        count++;

        if(count >N+2){

            return 1;
        }
    }

    return 1;
}

int main()
{
    ll N, M;
    cin >> N >> M;

    vector<vector<P>> E(N, vector<P>(0));

    vector<ll> cost(N, -INF);

    for (int i = 0; i < M; i++)
    {

        ll a, b, c;
        cin >> a >> b >> c;
        E[a - 1].push_back(make_pair(c, b - 1));
    }

    if (bell(cost, E) == 0)
    {

        cout << "inf" << endl;
    }
    else
    {
        cout << cost[N - 1] << endl;
    }

    return 0;
}