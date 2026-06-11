#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main (){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> to(N, vector<int>());
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;--b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    vector<int> count(N, -1);
    queue<int> que;
    que.push(0);
    count[0] = 0;
    while (!que.empty())
    {
        int y = que.front();
        que.pop();
        if (count[y] == 3)
        {
            break;
        }

        for (int x : to[y])
        {
            if (count[x] != -1)
            {
                continue;
            }
            count[x] = count[y] + 1;
            que.push(x);
        }     
    }
    
    if (count[N - 1] == 2)
    {
        cout << "POSSIBLE" << endl;
    } else
    {
        cout << "IMPOSSIBLE" << endl;
    }
    
    

    return 0;
    
}