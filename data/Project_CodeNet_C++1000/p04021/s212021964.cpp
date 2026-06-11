#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define ld long double
int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<ll>>;
ll inf=300000000000000000;
const double PI = 3.14159265358979323846;
const int MAX = 510000;
const ll MOD = 1000000007;
int main(){
  int n;
  cin >> n;
  set<int> even;
  set<int> odd;
  int b[n];
  rep(i,n){
    int u;
    cin >> u;
    if(i%2==0)even.insert(u);
    else odd.insert(u);
    b[i]=u;
  }
  sort(b,b+n);
  int cnt=0;
  rep(i,n){
    int u=b[i];
    if((i%2==0&&odd.count(u))||(i%2==1&&even.count(u)))cnt++;
  }
  cout << cnt/2 << endl;
}
