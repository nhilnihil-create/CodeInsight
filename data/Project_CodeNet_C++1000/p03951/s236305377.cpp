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
const int inf = 1000034000;
typedef vector<ll> vecl;
typedef vector<int> veci;
typedef tuple<string, int, int> TUP;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};


int main()
{
    int N;
    cin >> N;
    string S, T;
    cin >> S >> T;
    int ans = 2 * N;
    bool ok = true;
    int itr = 0;
    for (int i = N;i < 2 * N;i++)
    {
        string s = S.substr(i - N);
        string t = T.substr(0,2 * N - i);
        if (s == t)
        {
            ans -= s.size();
            break;
        }
    }
    cout << ans << endl;
}
