#include<iostream>
#include<cmath>
using namespace std;
 
int main(){
  long long n,ans, var;
  cin>>n;
  var = n%11;
  ans = n/11;
  ans *= 2;
  if(var>0) ans++;
  if(var>6) ans++;
  cout<<ans<<endl;
return 0;
}