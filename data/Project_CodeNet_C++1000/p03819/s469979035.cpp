#include <bits/stdc++.h>

using namespace std;

const int MaxN = 300005;

struct SegmentTree
{
    vector<int> Val, Low, High, Leaf;
    void Build(int x, int Left, int Right)
    {
        Low[x] = Left;
        High[x] = Right;
        if (Left == Right)
        {
            Leaf[Left] = x;
            return;
        }
        int Mid = (Left + Right) / 2;
        Build(x * 2, Left, Mid);
        Build(x * 2 + 1, Mid + 1, Right);
    }
    void Update(int x, int Left, int Right, int val)
    {
        if(Low[x] > Right || High[x] < Left)
        {
            return;
        }
        if (Low[x] >= Left && High[x] <= Right)
        {
            Val[x] += val;
            return;
        }
        Update(x * 2, Left, Right, val);
        Update(x * 2 + 1, Left, Right, val);
    }
    int Get(int x)
    {
        x = Leaf[x];
        int Resuft = 0;
        while (x > 0)
        {
            Resuft += Val[x];
            x /= 2;
        }
        return Resuft;
    }
    void Init(int n)
    {
        Val.assign(n * 4 + 5, 0);
        Low.assign(n * 4 + 5, 0);
        High.assign(n * 4 + 5, 0);
        Leaf.assign(n + 5, 0);
        Build(1, 1, n);
    }
};

int n, m;
pair<int, int> a[MaxN];
int Resuft[MaxN];
SegmentTree ST;

bool cmp(pair<int, int> x, pair<int, int> y)
{
    return (x.second - x.first) > (y.second - y.first);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    ST.Init(m);
    sort(a + 1, a + n + 1, cmp);
    int j = n;
    Resuft[1] = n;
    for (int i = 2; i <= m; i++)
    {
        while (a[j].second - a[j].first + 1 < i && j >= 1)
        {
            ST.Update(1, a[j].first, a[j].second, 1);
            j--;
        }
        Resuft[i] = j;
        for (int k = i; k <= m; k += i)
        {
            Resuft[i] += ST.Get(k);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << Resuft[i] << '\n';
    }
    
    return 0;
}
