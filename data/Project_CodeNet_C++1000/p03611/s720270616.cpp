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

    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    map<int, int> mp;
    int num;
    for (int i = 0; i < N; i++)
    {
        num = a[i];
        mp[num + 1]++;
        mp[num]++;
        mp[num - 1]++;
    }

    int ans = -1;
    for (auto iter = mp.begin(); iter != mp.end(); iter++)
    {
        ans = max(ans, iter->second);
    }
    cout << ans << endl;
}