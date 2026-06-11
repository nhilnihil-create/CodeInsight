//#include <tourist>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
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
ll n, m;
vector<ll> x;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    vector<map<ll, ll>> modv(m);
    for (int i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        x.push_back(temp);
        modv[temp % m][temp]++;
    }
    ll ans = 0;
    vector<bool> used(m, false);
    rep(i, m)
    {
        if(used[i])continue;
        if (i == 0 || i + i == m)
        {
            used[i]=true;
            ll count=0;
            ll sum=0;
            for (auto y : modv[i])
            {
                count += y.second / 2;
                sum+=y.second;
            }
            ans+=sum/2;
        }
        else
        {
            used[i]=true;
            used[m-i]=true;
            ll counti = 0;
            ll countm = 0;
            ll sumi=0;
            ll summ=0;
            for (auto y : modv[i])
            {
                counti += y.second / 2;
                sumi+=y.second;
            }
            for (auto y : modv[m - i])
            {
                countm += y.second / 2;
                summ += y.second;
            }
            if(sumi==summ){
                ans+=sumi;
            }
            else if(sumi>summ){
                ans+=summ;
                ll temp=sumi-summ;
                ans+=min(temp/2,counti);
            }
            else{
                ans += sumi;
                ll temp = summ - sumi;
                ans += min(temp / 2, countm);
            }
        }
    }
    cout << ans << "\n";
}
