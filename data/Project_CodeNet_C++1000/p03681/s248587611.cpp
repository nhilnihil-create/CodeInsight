#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod  1000000007
#define rep(i, n) for (int i = 0; i < n; ++i)
using Graph = vector<vector<int>>;
#define grepq priority_queue<double, std::vector<double>, std::greater<double>>
#define all(v) v.begin(),v.end()
#define PI acos(-1)

const ll INF = 10010001010;
const int inf = 2000000000;
ll lcm(ll a, ll b)
{
    return a * b / __gcd(a, b);
}

typedef tuple<string, int, int> TUP;

bool tuplesort(const TUP &right, const TUP &left)
{
    if (get<0>(right) != get<0>(left))
    {
        return get<0>(left) < get<0>(right);
    }
    if (get<1>(left) != get<1>(right))
    {
        return get<1>(left) > get<1>(right);
    }
    return get<2>(left) < get<2>(right);
}

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main(){
    ll N,M;
    cin >> N >> M;
    if(abs(N-M) > 1){
        cout << 0 << endl;
    }
    else{
        ll sum = 1;
        for (int i = 0; i < N; i++)
        {
            sum = sum * (i+1) % mod;
        }
        for (int i = 0; i < M; i++)
        {
            sum = sum * (i+1) % mod;
        }
        if (N == M)
        {
            sum = sum * 2 % mod;
        }
        cout << sum << endl;
    }
}