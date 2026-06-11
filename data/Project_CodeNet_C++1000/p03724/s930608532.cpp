#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, x, n) for (int i = x; i < (n); i++)
#define all(n) begin(n), end(n)
struct cww
{
    cww()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
} star;
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
typedef vector<int> vint;
typedef vector<char> vchar;
typedef vector<vector<int>> vvint;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef unsigned long long ull;

int main()
{
    int N, M;
    cin >> N >> M;
    vint cnt(N+1);
    for (size_t i = 0; i < M; i++)
    {
        int a,b;
        cin>>a>>b;
        cnt[a]++;
        cnt[b]++;
    }
    for (size_t i = 0; i < N; i++)
    {
        if(cnt[i]%2==1)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}