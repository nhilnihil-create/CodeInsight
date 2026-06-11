#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
int n, m;
unordered_map<int, bool> um;
vector<int> v[100001];
vector<int> ansf;
vector<int> ansr;
void dfsr(int node)
{
    // search rear hamiltonish path
    for (auto i : v[node])
    {
        if (um[i])
            continue;
        um[i] = true;
        ansr.push_back(i);
        dfsr(i);
        return;
    }
}
void dfsf(int node)
{
    //search front hamiltonish path
    for (auto i : v[node])
    {
        if (um[i])
            continue;
        um[i] = true;
        ansf.push_back(i);
        dfsf(i);
        return;
    }
}
int main()
{
    cin >> n >> m;
    rep(i, m)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    // check node 1
    // if the dimension is less than 1
    ansf.push_back(1);
    um[1] = true;
    dfsr(1);
    dfsf(1);
    reverse(ansf.begin(), ansf.end());
    cout << ansf.size() + ansr.size() << endl;
    for (auto i : ansf)
    {
        cout << i << ' ';
    }
    for (auto i : ansr)
    {
        cout << i << ' ';
    }
    cout << endl;
}