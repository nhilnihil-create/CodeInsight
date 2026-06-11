#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
  int n;
  cin >> n;
  ll a[n];
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  sort(a, a+n, greater<int>());
  ll ma=0, mi=0;
  for(int i=1; i<n; i++){
    if(a[i-1]==a[i]){
      if(ma==0){
        ma = a[i];
        i++;
      }
      else if(mi==0){
        mi = a[i];
        break;
      }
    }
  }
  cout << ma*mi << endl;
       
       
  return 0;
}
