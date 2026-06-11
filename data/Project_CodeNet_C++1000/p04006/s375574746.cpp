#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long int n,x;
    cin >> n >> x;
  long long int a[2010],b[2010];
  long long int ans =0 ;
  
  for(int i=0;i<n;i++)
    cin >> a[i] ;
  
 for(int i=0;i<n;i++){
   b[i] = a[i];
   ans += a[i];
 }
  
  for(int i=1;i<n;i++){
   long long int res = i*x;
    
    for(int j=0;j<n;j++){
     b[j] = min(b[j],a[(j+n-i)%n]);
      res += b[j];
    }
    
  ans = min(res,ans);
  }
  cout << ans << endl;
}
      
      
