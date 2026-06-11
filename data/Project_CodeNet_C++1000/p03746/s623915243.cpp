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
  int n,m;
  cin >> n >> m;
  Graph k(n);
  rep(i,m){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    k[a].push_back(b);
    k[b].push_back(a);
  }
  int u[n];
  rep(i,n)u[i]=0;
  u[0]=1;
  u[k[0][0]]=1;
  vector<int> a;
  vector<int> b;
  int o=0;
  while(true){
    a.push_back(o);
    int nxt=-1;
    for(int v: k[o]){
      if(u[v]==0){
        nxt=v;
      }
    }
    if(nxt==-1)break;
    o=nxt;
    u[o]++;
  }
  o=k[0][0];
  while(true){
    b.push_back(o);
    int nxt=-1;
    for(int v: k[o]){
      //if(o==1&&v==3)cout << u[v] << endl;
      if(u[v]==0){
        nxt=v;
      }
    }
    if(nxt==-1)break;
    o=nxt;
    u[o]++;
  }
  cout << a.size()+b.size() << endl;
  rep(i,a.size())cout << a[a.size()-1-i]+1 << " ";
  //cout << endl;
  rep(i,b.size()-1)cout << b[i]+1 << " ";
  cout << b[b.size()-1]+1 << endl;
  //cout << k[0][0] << endl;
}
