#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
typedef long long ll;
const int INF = 1<<29;
const int N = 1e6 + 9;
ll a[N];
bool cmp(const pair<double, ll> &a, const pair<double, ll> &b)
{
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.second > b.second;
}
int main()
{
    fio;
    ll n, ans = 0;
    cin >> n;
    ll minn = INF;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
    for(int i = -100; i <= 100; i ++)
    {
        for(int j = 0; j < n; j ++)
        {
            ans += ((a[j] - i) * (a[j] - i));
        }
        minn = min(ans, minn);
        ans = 0;
    }
    cout << minn;
    return 0;
}
