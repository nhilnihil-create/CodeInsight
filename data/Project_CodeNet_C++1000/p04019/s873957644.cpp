#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
ll gcd(ll a,ll b) {return  b ? gcd(b,a%b) : a;}
const long long INF = 1LL << 60;
const int mod = 1000000007;
const double PI = acos(-1.0);
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int main () {
     string s;
     cin >> s;
     set<char> se;
     rep(i,s.size()){
          se.insert(s[i]);
     }     
     if(se.size()==4) cout << "Yes" <<endl;
     else if(se.size()==2&&se.count('E')&&se.count('W')){
          cout << "Yes" <<endl;
     }
     else if(se.size()==2&&se.count('N')&&se.count('S')){
          cout << "Yes" <<endl;
     }
     else cout << "No" <<endl;
}