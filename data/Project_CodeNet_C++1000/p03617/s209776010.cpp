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
    ll Q, H, S, D;
    ll N;
    cin >> Q >> H >> S >> D >> N;
    ll ans = 0;
    if(N == 1){
        ans = min({Q * 4, H * 2, S});
    }
    else{
        S = min({Q * 4,H * 2,S});
        D = min(D,S * 2);
        if(N % 2== 0){
            ans += min(2 * S, D) * (N / 2);
        }
        else{
            ans += S;
            ans += min(2 * S, D) * (N / 2);
        }
    }
    cout << ans << endl;
}
