#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
ll gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<ll>>;
ll inf=300000000000000000;
const double PI = 3.14159265358979323846;
int main(){
  int n,m;
  cin >> n >> m;
  if(m==1){
    cout << n/2 << endl;
    return 0;
  }
  vector<int> k(m,0);
  vector<int> u(m,0);
  map<int,int> o;
  rep(i,n){
    int a;
    cin >> a;
    o[a]++;
  }
  for(pair<int,int> p: o){
    int a=p.first,b=p.second;
    a=a%m;
    k[a]+=b;
    u[a]+=b/2*2;
  }
  int ans=k[0]/2;
  if(m%2==0){
    ans+=k[m/2]/2;
  }
  rep(i,(m-1)/2){
    //cout << ans << endl;
    if(k[i+1]>=k[m-1-i]){
      ans+=k[m-1-i];
      ans+=min(u[i+1]/2,(k[i+1]-k[m-1-i])/2);
    }
    else{
      ans+=k[i+1];
      ans+=min(u[m-i-1]/2,(k[m-i-1]-k[i+1])/2);
    }
  }
  cout << ans << endl;
}
