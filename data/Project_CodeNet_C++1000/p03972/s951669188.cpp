//#include <tourist>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;
const ll LINF = ll(1e18) + 1;
const int MOD = 1000000007;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, Dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define debug(v)          \
    cout << #v << ":";    \
    for (auto x : v)      \
    {                     \
        cout << x << ' '; \
    }                     \
    cout << endl;
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
//cout<<fixed<<setprecision(15);有効数字15桁
//-std=c++14
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll h,w;
vector<ll> p,q;;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> w>>h;
    ll ans=0;
    for (int i = 0; i <w; i++)
    {
        ll temp;
        cin >> temp;
        p.push_back(temp);
        ans+=temp;
    }
    for (int i = 0; i <h; i++)
    {
        ll temp;
        cin >> temp;
        q.push_back(temp);
        ans+=temp;
    }
    sort(ALL(p));
    vector<ll> sum(w+1,0);
    for(int i=1;i<=w;i++){
        sum[i]=sum[i-1]+p[i-1];
    }
    for(int i=0;i<h;i++){
        auto iter=lower_bound(ALL(p),q[i]);
        ll temp=iter-p.begin();
        ans+=q[i]*(w-temp);
        ans+=sum[temp];
    }
    cout << ans << "\n";
}
