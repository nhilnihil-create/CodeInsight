#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<string> vs;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define REPR(i,n) for(int i=n-1;i>=0;i--)
#define FORR(i,n,m) for(int i=n-1;i>=m;i--)
#define ARR(array) for(int i=0;i<array.size();i++)
#define all(in) (in).begin(),(in).end()
#define ALL(in,K) (in),(in)+(K)

#define INF 1e18
#define MOD 1000000007
#define SIZE 10005
#define PI 	3.14159265358979323846

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; } //最大公約数
ll lcm(ll a, ll b) { return a/gcd(a, b)*b; } //最小公倍数

ll input(){
  ll a;
  cin >> a;
  return a;
}

int main(){
  string s;
  cin >> s;
  REP(i,s.size()){
    cout << s.at(i);
    if(i==3)cout << " ";
  }
  cout << endl;
}