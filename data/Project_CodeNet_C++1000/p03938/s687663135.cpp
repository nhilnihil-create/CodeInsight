//#include <tourist>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = (1 << 28);
const int MOD = 1000000007;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, Dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl; 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
//setprecision(15)有効数字15桁
//-std=c++14
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a * b / gcd(a, b);}
ll n;
vector<ll> t;
vector<ll> a(20000), b(20000);
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        temp--;
        t.push_back(temp);
    }
    a[t[0]]=0;
    b[t[0]]=0;
    ll base=t[0];
    for(ll i=1;i<n;i++){
        ll now=t[i];
        a[now]=i+n*(now-base);
        b[now]=i+n*(base-now);
    }
    ll temp=a[0];
    for(int i=0;i<n;i++){
        a[i]-=temp;
        a[i]++;
    }
    temp=b[n-1];
    for(int i=0;i<n;i++){
        b[i]-=temp;
        b[i]++;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<n;i++){
        cout<<b[i]<<" ";
    }
    cout<<"\n";
}

