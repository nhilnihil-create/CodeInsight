#include<iostream>
using namespace std;
int main()
{
  int n,t,tt,ts,te,i,res=0;
  cin >> n >> t;
  cin >> ts;
  te=ts+t;
  for(i=1;i<n;i++){
    cin >> tt;
    if(tt>te){
      res+=te-ts;
      ts=tt;
    }
    te=tt+t;
  }
  res+=te-ts;
  cout << res << endl;
  return 0;
}