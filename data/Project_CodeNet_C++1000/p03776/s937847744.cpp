#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int N_MAX=50;
typedef long long ll;
int main()
{
  int n,a,b,m,k,t=0,i;
  ll c=1,res;
  ll v[N_MAX];
  long double s=0;
  cin >> n >> a >> b;
  for(i=0;i<n;i++)
    cin >> v[i];
  sort(v,v+n,greater<ll>());
  for(i=0;i<a;i++){
    s+=v[i];
    if(i>0&&v[i]<v[i-1])
      t=i;
  }
  s/=a;
  for(;i<n;i++)
    if(v[i]<v[t])
      break;
  m=i-t;
  k=a-t;
  for(i=1;i<=k;i++){
    c*=m+1-i;
    c/=i;
  }
  res=c;
  if(t==0)
    for(;i<=min(m,b);i++){
      c*=m+1-i;
      c/=i;
      res+=c;
    }
  cout << setprecision(10) << s << endl; 
  cout << res << endl;
  return 0;
}