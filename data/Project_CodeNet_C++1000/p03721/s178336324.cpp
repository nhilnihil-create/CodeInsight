#include <bits/stdc++.h>
using namespace std;

int64_t mod = 1000000007;
int64_t large = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int64_t N, K;
    cin >> N >> K;
    vector<pair<int, int>> list;
    for (int i = 0; i < N; i++)
    {
        int64_t p, q;
        cin >> p >> q;
        list.push_back(make_pair(p, q));
    }
    sort(list.begin(), list.end());
    int64_t sum = 0;
    for (int64_t i = 0; i < N; i++)
    {
        sum += list[i].second;
        if (sum >= K)
        {
            cout << list[i].first;
            break;
        }
    }
}