#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod 1000000007
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
    int N;
    cin >> N;
    vector<int> A(3 * N);
    ll ans = 0;
    vector<int> G(N);
    for (int i = 0; i < 3 * N; i++)
    {
        cin >> A[i];
    }
    sort(all(A));
    for (int i = N; i < 3 * N;i+= 2)
    {
        ans += A[i];
    }
    cout << ans << endl;
}
