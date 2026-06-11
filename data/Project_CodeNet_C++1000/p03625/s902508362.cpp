#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    int N;
    cin >> N;

    int num;
    map<ll, ll> mapping;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        mapping[num]++;
    }
    // debug
    // for (auto itr = box.begin(); itr != box.end(); itr++)
    // {
    //     cout << itr->first <s< ":" << itr->second << endl;
    //
    ll first = 0;
    ll second = 0;
    for (auto itr = mapping.begin(); itr != mapping.end(); itr++)
    {
        num = itr->second;
        if (num >= 2)
        {
            second = first;
            first = itr->first;
        }
        if (num >= 4)
        {
            second = first;
        }
    }
    ll ans = first * second;
    cout << ans << endl;
    return (0);
}