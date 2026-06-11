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
  int n;
  cin >> n;
  int a[n];
  rep(i,n){
    int b;
    cin >> b;
    b--;
    a[b]=i;
  }
  //rep(i,n)a[i]=i;
  set<int> s;
  s.insert(n);
  set<int> t;
  t.insert(1);
  ll ans=0;
  rep(i,n){
    if(i%1000==0){
      //cout << clock() << endl;
    }
    int b=a[i];
    ans+=(ll)(i+1)*(ll)(*s.lower_bound(b)-b)*(ll)(b-(*t.lower_bound(-1*b))*-1);
    //cout << ans << " " << (*lower_bound(s.begin(),s.end(),b)-b) << " " <<  (*lower_bound(t.begin(),t.end(),-1*b)-b) << " " << b << endl;
    s.insert(b);
    t.insert(-1*b);
  }
  cout << ans << endl;
}
