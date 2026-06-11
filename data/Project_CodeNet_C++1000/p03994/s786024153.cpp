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
ll n, k;
string s;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> s>>k;
    n=s.size();
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i]=s[i]-'a';
    }
    string ans="";
    for(int i=0;i<n;i++){
        if(a[i]==0){
            ans+='a';
        }
        else if(k>=26-a[i]){
            k-=26-a[i];
            ans+='a';
        }
        else{
            ans+=s[i];
        }
    }
    int temp=ans[n-1]-'a';
    temp+=k;
    temp%=26;
    ans[n-1]='a'+temp;
    cout << ans << "\n";
}

