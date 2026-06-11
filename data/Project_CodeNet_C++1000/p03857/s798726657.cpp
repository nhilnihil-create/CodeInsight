#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<sstream>
#include<cmath>
#include<climits>
#include<algorithm>
#include<bitset>
#include<set>
#include<stack>
#include<queue>
#include<iomanip>
#include<memory.h>
#include<complex>
using namespace std;  
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef tuple<int,int> tii;
#define rep(i,n) for(ll i=0;i<(n);i++)  
#define pb push_back
#define mt make_tuple
#define ALL(a) (a).begin(),(a).end()
#define FST first
#define SEC second  
const int INF = (INT_MAX/2);
const ll LLINF = (LLONG_MAX/2);
const double eps = 1e-8;
const double PI = M_PI;  
#define DEB cerr<<"!"<<endl
#define SHOW(a,b) cerr<<(a)<<" "<<(b)<<endl
#define SHOWARRAY(ar,i,j) REP(a,i)REP(b,j)cerr<<ar[a][b]<<((b==j-1)?((a==i-1)?("\n\n"):("\n")):(" "))
#define DIV int(1e9+7)
inline ll pow(ll x,ll n,ll m){ll r=1;while(n>0){if((n&1)==1)r=r*x%m;x=x*x%m;n>>=1;}return r%m;}
inline ll lcm(ll d1, ll d2){return d1 / __gcd(d1, d2) * d2;}
 
/* Coding Space*/
class UF{
public:
  vi value;
  vi over; // When over < 0, 'over' keep number of node(using negative number). -1 means this tree is a node.
  int root(int index){
    int t = index;
    stack<int> stack_i;
    while(over[t] >= 0){
      stack_i.push(t);
      t = over[t];
    }
    while(!stack_i.empty()){
      int i = stack_i.top(); stack_i.pop();
      over[i] = t;
    }// reconnect
    return t;
  }
  void merge(int a,int b){
    if(this->root(a) == this->root(b)) return;
    over[root(a)] += over[root(b)]; // over have a number of nodes.
    over[root(b)] = root(a);
  }
  int NumNode(int a){
    return -over[root(a)];
  }
  UF(int Nodes){
    value.resize(Nodes);
    over.resize(Nodes);
    rep(i,Nodes)
      over[i] = -1;
  }
};
typedef tuple<int,int> tii;
int main(){
  UF road(2*100001);
  UF train(2*100001);
  int n,k,l; cin >> n >> k >> l;
  rep(i,k){
    int a,b; cin >> a >> b;a--,b--;
    road.merge(a,b);
  }
  rep(i,l){
    int a,b; cin >> a >> b;a--,b--;
    train.merge(a,b);
  }
  map<tii,int> m;
  rep(i,n){
    m[tii{road.root(i),train.root(i)}]++;
  }
  rep(i,n){
    cout << m[tii{road.root(i),train.root(i)}] << (i==n-1?"\n":" ");
  }
}