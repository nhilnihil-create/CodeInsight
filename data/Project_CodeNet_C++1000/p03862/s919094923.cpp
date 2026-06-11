#include<iostream>
#include<string>
using namespace std;
int N_MAX = 100000;
typedef long long ll;
int main()
{
  int n,i;
  ll x,res=0;
  ll a[N_MAX];
  cin >> n >> x;
  cin >> a[0];
  if(a[0]>x){
    res+=a[0]-x;
    a[0]=x;
  }
  for(i=1;i<n;i++){
    cin >> a[i];
    if(a[i]+a[i-1]>x){
      res+=a[i]+a[i-1]-x;
      a[i]=x-a[i-1];
    }
  }
  cout << res << endl;
  return 0;
}