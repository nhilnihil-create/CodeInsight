#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main()
{
    int n;
    cin >> n;
    set<int> dou;
    vector<int> can;
    int a;
    rep(i, n)
    {
        cin >> a;
        if (dou.find(a) != dou.end())
        {
            can.push_back(a);
            dou.erase(dou.find(a));
        }
        else
        {
            dou.insert(a);
        }
    }

    if (can.size() < 2)
    {
        cout << 0 << endl;
    }
    else
    {
        sort(can.begin(), can.end());
        cout << (long long)(can[can.size() - 1]) * can[can.size() - 2] << endl;
    }
    return 0;
}