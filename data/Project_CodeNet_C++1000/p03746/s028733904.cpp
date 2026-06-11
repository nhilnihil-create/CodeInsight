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
//setprecision(15)有効数字15桁
//-std=c++14
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int n, m;
vector<bool> used(100000,false);
    vector<int>ans_pr,ans;
vector<vector<int>> v(100000);
void dfs(int now,int prev){
        used[now]=true;
        /*
        if(now==0){
            if(!used[v[0][0]])
            dfs(v[0][0],0);
        }
        else{
            ans.push_back(now);
            bool check=false;
            for(int i=0;i<v[now].size();i++){
                if(!used[v[now][i]]){
                    dfs(v[now][i],now);
                    break;
                }
            }
        }
        */
       ans.push_back(now);
            for(int i=0;i<v[now].size();i++){
                if(!used[v[now][i]]){
                    dfs(v[now][i],now);
                    break;
                }
            }
    }
    void dfsp(int now,int prev){
        used[now]=true;
        if(now==0){
            dfsp(v[0][0],0);
        }
        else{
            ans_pr.push_back(now);
            for(int i=0;i<v[now].size();i++){
                if(!used[v[now][i]]){
                    dfsp(v[now][i],now);
                    break;
                }
            }
        }
    }
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n>>m;
    for (int i = 0; i < m; i++)
    {
        int temp,temp1;
        cin >> temp>>temp1;
        temp--;
        temp1--;
        v[temp].push_back(temp1);
        v[temp1].push_back(temp);
    }
    dfsp(0,-1);
    dfs(0,-1);
    if(ans_pr.size()>=1)
    reverse(ALL(ans_pr));
    cout<<ans.size()+ans_pr.size()<<"\n";
    rep(i,ans_pr.size()){
        cout << ans_pr[i]+1 << "\n";
    }
    rep(i,ans.size())
    cout << ans[i]+1 << "\n";
}
