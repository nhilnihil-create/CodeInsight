#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

class WeightedGraph
{
private:
    const int INF = 1e9;
    int m_nodeNum;
    vector<vector<int>> m_adList;
    vector<vector<int>> m_weights;
    vector<vector<int>> m_dists;

    void DFS(const int v)
    {
        deque<int> Q{ v };
        vector<int> dists(m_nodeNum, INF);
        dists[v] = 0;
        while (!Q.empty())
        {
            const int u = Q.front(); Q.pop_front();
            for (const int n : m_adList[u])
            {
                if (dists[n] > dists[u] + m_weights[u][n])
                {
                    dists[n] = dists[u] + m_weights[u][n];
                    Q.push_back(n);
                }
            }
        }
        m_dists[v] = dists;
    }

public:

    WeightedGraph(int nodeNum) : m_nodeNum(nodeNum)
    {
        m_adList.assign(nodeNum, vector<int>());
        m_weights.assign(nodeNum, vector<int>(nodeNum));
        m_dists.assign(nodeNum, vector<int>(nodeNum, INF));
    }

    void AddEdge(const int v1, const int v2, const int weight)
    {
        m_adList[v1].push_back(v2);
        m_adList[v2].push_back(v1);
        m_weights[v1][v2] = m_weights[v2][v1] = weight;
    }

    void ComputeDistance()
    {
        for (int v = 0; v < m_nodeNum; ++v)
        {
            DFS(v);
        }
    }

    const int GetDistance(const int v1, const int v2)
    {
        return m_dists[v1][v2];
    }
};

int main()
{
    int N, M, R; cin >> N >> M >> R;    // N <= 200, R <= 8
    vector<int> rs(R);
    for (auto &ri : rs)
    {
        cin >> ri;
        --ri;
    }
    WeightedGraph graph(N);
    // 全ての街間の最短移動距離を計算し，全ての経路順(高々R! <= 8! = 40,320)を試す
    for (int i = 0; i < M; ++i)
    {
        int ai, bi, ci; cin >> ai >> bi >> ci; --ai; --bi;
        graph.AddEdge(ai, bi, ci);
    }
    // 前処理：全ての頂点間の距離を計算:O(N^2?)
    graph.ComputeDistance();
    // 全ての経路順を試す:O(R!*R)
    LLONG minDist = 1e9;
    sort(rs.begin(), rs.end());
    do
    {
        LLONG dist = 0;
        for (int i = 0; i < R - 1; ++i)
        {
            dist += graph.GetDistance(rs[i], rs[i + 1]);
        }
        minDist = min(minDist, dist);
    } while (next_permutation(rs.begin(), rs.end()));
    cout << minDist << endl;
}
