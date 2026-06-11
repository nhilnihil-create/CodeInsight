#include <stdlib.h>
#include <iostream>
#include <math.h>
 
using namespace std;
 
int main(){
  int n; cin >> n;
  int a[n];
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  int ans = 0;
  for(int i=1;i<=n;i++){
      if(i==a[a[i-1]-1] && i != a[i-1]){
        ans++;
        //a[i-1]=0;
      }
    
  }
  cout << ans/2 << endl;
}