#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
ll gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<int>>;
ll inf=300000000000000000;
const double PI = 3.14159265358979323846;
int main(){
  string s,t;
  cin >> s >> t;
  int q;
  cin >> q;
  int ss=s.size();
  int tt=t.size();
  int u[ss+1];
  int v[tt+1];
  u[0]=0;
  v[0]=0;
  rep(i,ss){
    if(s[i]=='B')u[i+1]=(u[i]+2)%3;
    else u[i+1]=(u[i]+1)%3;
  }
  rep(i,tt){
    if(t[i]=='B')v[i+1]=(v[i]+2)%3;
    else v[i+1]=(v[i]+1)%3;
  }
  rep(i,q){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if((3+u[b]-u[a-1])%3==(3+v[d]-v[c-1])%3)cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  //rep(i,ss+1)cout << u[i] << endl;
  //rep(i,tt+1)cout << v[i] << endl;
}
