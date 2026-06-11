#include<iostream>
using namespace std;
int main(){
  int n,t,ans,i;
  cin >> n >> t;
  ans = n*t;
  int x[n];
  for(i=0;i<n;i++){
    cin >> x[i];
    if (i != 0){
      if (x[i]-x[i-1] < t){
        ans -= t-(x[i]-x[i-1]);
      }
    }
  }
  cout << ans << endl;
}