#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
  int n,m=101,s=0,t,i,res;
  cin >> n;
  for(i=0;i<n;i++){
    cin >> t;
    s+=t;
    if(t%10!=0)
      m=min(m,t);
  }
  res=s;
  if(s%10==0){
    res=s-m;
    if(m>100)
      res=0;
  }
  cout << res << endl;
  return 0;
}