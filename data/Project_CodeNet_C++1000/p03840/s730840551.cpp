#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  long long int a,b,c,d,e,f,g; 
  cin >> a >> b >> c >> d >> e >> f >> g;
  long long int ans =0;
  if((a%2)  +  (d%2)  + (e%2) >= 2 && a>0 && d>0 && e>0){
    ans = ans+6;
    a--; d--; e--;
  }
  ans =ans+ 4*(a/2) + 2*b + 4 * (d/2) + 4*(e/2);
  cout << ans/2 << endl;
  return 0;
}
