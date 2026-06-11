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
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n>>m;
    map<char,int> ms;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        for(int j=0;j<m;j++)ms[temp[j]]++;
    }
    map<int,int> mi;
    for(char i='a';i<='z';i++){
        mi[4]+=ms[i]/4;
        ms[i]%=4;
        mi[2]+=ms[i]/2;
        ms[i]%=2;
        mi[ms[i]]++;
    }
    //cout<<mi[4]<<" "<<mi[2]<<" "<<mi[1]<<"\n";
    if(n%2&&m%2){
        if(mi[1]!=1)return no,0;
        if(mi[2]>n/2+m/2) return no,0;
    }
    if(n%2&&!(m%2)){
        if(mi[1]!=0)return no,0;
        if(mi[2]>m/2)return no,0;
    }
    if(m%2&&!(n%2)){
        if(mi[1]!=0)return no,0;
        if(mi[2]>n/2)return no,0;
    }
    if(!(n%2)&&!(m%2)){
        if(mi[1]!=0)return no,0;
        if(mi[4]!=m*n/4)return no,0;
    }
    yes;
}

