#include <bits/stdc++.h>
using namespace std;
//型に気を付けよう
//a=0x61=97
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long  ll;
typedef long double  ld;
typedef string str;
typedef pair<int,int> pairii;
typedef vector<int> veci;
const double pi=3.1415926535;
const ll  mod=1000000007;
//桁数指定　cout << fixed << setprecision(2)
int main() {
  int a,b,c,d,ans=0;
  cin>>a>>b>>c>>d;
  ans=-(max(a,c)-min(b,d));
  cout<<(ans<0?0:ans)<<endl;       
}