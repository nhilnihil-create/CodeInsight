#include <bits/stdc++.h>
#define rep(i,m,n) for(int i=m;i<n;i++)
#define fix(n) cout<<fixed<<setprecision(n)
#define co(n) cout<<n<<endl
#define all(n) (n).begin(),(n).end()
using namespace std;
typedef long long ll;
const ll mod=1000000007;
double pi=3.1415926535;

int main(){
  ll a,b,n,x;
  cin>>a>>b>>n;
  string s="No";
  
  rep(i,0,a+1){
    rep(j,0,b+1){
      x=i*b+j*a-2*i*j;
      if(x==n) s="Yes";
    }
  }
  co(s);
    
  return 0;
}