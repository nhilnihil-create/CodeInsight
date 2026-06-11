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
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
ll n, a, b, c, d;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n>>a>>b>>c>>d;
    if(d*(n-1)<abs(a-b)){
            return NO,0;
    }
    ll sa=d-c;
    ll centers=2*c;
    ll atumi=1;
    ll block=1;
    for(int i=0;i<n-1;i++){
        if(i!=0){
        centers-=sa;
        }
        atumi+=sa;
        block++;
    }
    if(centers<=0){
        return YES,0;
    }
    //cout<<atumi<<" "<<centers<<"\n";
    ll le=abs(a-b);
    ll kyori;
    ll tani=centers+atumi-1;
    if(n%2){
        kyori=atumi/2;
        if(le<=kyori){
            return YES,0;
        }
        ll amari=(le-kyori)%tani;
        if(amari==0){
            return YES,0;
        }
        if(amari<centers){
            return NO,0;
        }
        return YES,0;
    }
    else{
        kyori=centers/2;
        if(le<kyori){
            return NO,0;
        }
        ll amari=(le-kyori)%tani;
        if(amari<atumi){
            return YES,0;
        }
        return NO,0;
    }
}
