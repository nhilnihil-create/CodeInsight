#include <bits/stdc++.h>
using namespace std;

int N;
vector<set<int>> edge;

vector<int> get_path(int from, int to)
{
    vector<int> parent(N, -2);
    parent[from] = -1;
    queue<int> st;
    st.push(from);
    while (!st.empty())
    {
        int now = st.front();
        st.pop();
        if (now == to) break;
        for (auto nxt : edge[now])
        {
            if (parent[nxt] == -2)
            {
                parent[nxt] = now;
                st.push(nxt);
            }
        }
    }
    int tmp = to;
    vector<int> res;
    while (tmp != from)
    {
        res.push_back(tmp);
        tmp = parent[tmp];
    }
    res.push_back(from);
    reverse(res.begin(), res.end());
    return res;
}

int countConnected(int start)
{
    vector<bool> visited(N, false);
    queue<int> st;
    st.push(start);
    visited[start] = true;
    while (!st.empty())
    {
        int now = st.front();
        st.pop();
        for (auto nxt : edge[now])
        {
            if (!visited[nxt])
            {
                visited[nxt] = true;
                st.push(nxt);
            }
        }
    }
    int res = 0;
    for (auto v : visited) if (v) res++;
    return res;
}

int main()
{
    cin >> N;
    edge.resize(N);
    for (int i = 0; i < N - 1; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        tmp1--; tmp2--;
        edge[tmp1].insert(tmp2);
        edge[tmp2].insert(tmp1);
    }

    vector<int> path = get_path(0, N - 1);
    int l = path.size();
    int e1 = path[(l - 1) / 2];
    int e2 = path[(l - 1) / 2 + 1];
    edge[e1].erase(e2);
    edge[e2].erase(e1);
    // cout << countConnected(0) << " " << countConnected(N - 1) << endl;

    if (countConnected(0) <= countConnected(N-1)) cout << "Snuke" << endl;
    else cout << "Fennec" << endl;
}