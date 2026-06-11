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
int main(){
  int a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;
  int w[31];
  int s[3001];
  rep(i,31)w[i]=0;
  rep(i,3001)s[i]=0;
  w[a]=1;
  w[b]=1;
  s[c]=1;
  s[d]=1;
  rep(i,31){
    if(i>=a){
      if(w[i-a]==1)w[i]=1;
    }
    if(i>=b&&w[i]==0){
      if(w[i-b]==1)w[i]=1;
    }
  }
  rep(i,3001){
    if(i>=c){
      if(s[i-c]==1)s[i]=1;
    }
    if(i>=d&&s[i]==0){
      if(s[i-d]==1)s[i]=1;
    }
  }
  int ansa=a*100,ansb=0;
  ld max=0;
  rep(i,30){
    int y=i+1;
    if(w[y]==0)continue;
    int u=min(f-y*100,y*e);
    if(u<1)continue;
    while(s[u]==0&&u>0){
      u--;
    }
    if(max<(ld)u/(ld)y){
      max=(ld)u/(ld)y;
    ansa=u+y*100;
    ansb=u;
    }
  }
  cout << ansa << " " << ansb << endl;
}  
