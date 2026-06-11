#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod107 1000000007
#define rep(i, n) for (int i = 0; i < n; ++i)
using Graph = vector<vector<int>>;
#define grepq priority_queue<double, std::vector<double>, std::greater<double>>
#define all(v) v.begin(), v.end()
#define PI acos(-1) 

const ll INF = 10010001010;
const int inf = 2000000000;


typedef tuple<string, int, int> TUP;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
    ll A, B, C;
    cin >> A >> B >> C;
    ll ans = 0;
    ll y = min(A,min(B,C));
    ll x = max(A,max(B,C));
    ll z = A + B + C - y - x;
    if (A % 2 == 0 || B % 2 == 0 || C % 2 == 0)
    {
        ans = 0;
    }
    else{
        ll ookii = x - x / 2;
        ll tiisai = x - ookii;
        ans = abs(ookii - tiisai) * y * z;
    }
    cout << ans << endl;
}
