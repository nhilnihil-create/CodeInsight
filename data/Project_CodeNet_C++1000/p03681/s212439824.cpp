#include<iostream>
using namespace std;
int p=1e9+7;
int main()
{
  long long n,m,i,res;
  cin >> n >> m;
  if(n>m+1 || m>n+1){
    cout << "0" << endl;
    return 0;
  }
  if(n==m){
    res=2;
  }else if(n==m+1){
    res=n;
    n--;
  }else{
    res=m;
  }
  for(i=2;i<=n;i++){
    res*=i;
    res%=p;
    res*=i;
    res%=p;
  }
  cout << res << endl;
  return 0;
}