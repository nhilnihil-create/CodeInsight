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
ll n;
map<int,int>m;
vector<vector<pair<int,int>> >g(100000);
vector<vector<pair<int,int>> >vsp(100000);
void makeg(int k){
    for(int i=0;i<vsp[k].size();i++){
        g[k].push_back(make_pair(vsp[k][i].second,i+1));
        makeg(vsp[k][i].second);
    }
}
int dfs(int k,int count){
    int ans=count;
    for(int i=0;i<g[k].size();i++){
        chmax(ans,dfs(g[k][i].first,count+g[k][i].second));
    }
    return ans;
}
vector<int> dp(100000,-1);
vector<vector<int> > vs(100000);
int dfs1(int k){
    if(dp[k]!=-1)return dp[k];
    if(vs[k].size()==0){
        dp[k]=0;
        return 0;
    }
    vector<int>v;
    for(int i=0;i<vs[k].size();i++){
        v.push_back(dfs1(vs[k][i]));
    }
    sort(ALL(v));
    int ans=0;
    for(int i=0;i<v.size();i++){
        chmax(ans,v[v.size()-1-i]+i);
    }
    dp[k]=ans+1;
    return dp[k];
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int temp;
        cin >> temp;
        temp--;
        vs[temp].push_back(i);//tempにiが倒される
        m[temp]++;
    }
    /*
    for(int i=0;i<n;i++){
        for(int j=0;j<vs[i].size();j++){
            vsp[i].push_back(make_pair(-m[vs[i][j]],vs[i][j]));
        }
    }
    for(int i=0;i<n;i++){
        if(vsp[i].size()!=0)
        sort(ALL(vsp[i]));
    }
    */
    dfs1(0);
    //makeg(0);
    //debug(dp);
    cout << dp[0] << "\n";
}
