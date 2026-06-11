#include <iostream>
#include <vector>
using namespace std;
long long ans;
int N, M;
vector <int> G[100005];
int Colour[100005], cnt;
bool ok = 1;
void Read()
{
    cin >> N >> M;
    for(int i = 1; i <= M; i++)
    {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
}

void DFS(int node, int colour)
{
    Colour[node] = colour;
    ++cnt;
    for(int i = 0; i < G[node].size(); i++)
    {
        int neighb = G[node][i];
        if(Colour[neighb] == 0)
        {
            DFS(neighb, 3 - colour);
        }
        else
        {
            if(Colour[neighb] == colour)
                ok = 0;
        }
    }
}

void Solve()
{
    long long odd = 0, even = 0, isolate = 0;
    for(int i = 1; i <= N; i++)
    {
        ok = 1;
        cnt = 0;
        if(Colour[i] == 0)
        {
            DFS(i, 1);
            if(cnt == 1)
            {
                ++isolate;
                continue;
            }
            if(ok == 0)
                odd++;
            else
                even++;
        }
    }
    ans += even * 2 + odd;
    ans += odd * (odd - 1);
    ans += 2 * even * (even - 1);
    ans += 2 * even * odd;
    ans += isolate * (N - 1) * 2 + isolate;
    ans -= isolate * (isolate - 1);
    cout << ans << "\n";
}
int main()
{
    Read();
    Solve();
    return 0;
}
