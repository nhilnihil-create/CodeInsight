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
int n, m;
vector<int> a;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    //同じ数で一個のグループができたら死
    int maxa=0, mina=INF;
    map<int,int> m;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        a.push_back(temp);
        m[temp]++;
        chmax(maxa,temp);
        chmin(mina,temp);
    }
    sort(ALL(a));
    if(maxa-mina>1)return no,0;
    if(maxa-mina==0){
        if(a[0]==n-1)return yes,0;
        if(n/a[0]>=2){
            return yes,0;
        }
    }
    else{
        if(m[a[n-1]]<2){
            return no,0;
        }
        if(m[a[0]]+m[a[n-1]]/2>=a[n-1]&&m[a[0]]+1<=a[n-1])return yes,0;
    }
    no;
}

