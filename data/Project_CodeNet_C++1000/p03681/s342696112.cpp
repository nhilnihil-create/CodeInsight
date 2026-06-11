#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
  int n,m;
  cin >> n >> m;
  int dif=abs(n-m);
  if(dif>=2)cout << 0 << endl;
  else{
      ll ans=1;
      if(n==m){
          for(int i=1;i<=n;i++){
              ans*=(i%MM);
              ans%=MM;
          }
          for(int i=1;i<=m;i++){
              ans*=(i%MM);
              ans%=MM;
          }
          ans*=2;
          ans%=MM;
          cout << ans << endl;
      }
      else{
          for(int i=1;i<=n;i++){
              ans*=(i%MM);
              ans%=MM;
          }
          for(int i=1;i<=m;i++){
              ans*=(i%MM);
              ans%=MM;
          }
          ans%=MM;
          cout << ans << endl;
      }
  }
}