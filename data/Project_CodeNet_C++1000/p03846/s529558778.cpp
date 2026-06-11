#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin >> n;
  if(n==1){
    int a;
    cin >> a;
    if(a==0) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
  }
  int a[n],b[n];
  if(n%2==1) for(int i=0; i<n; i++){
    b[i] = ((i+1)/2)*2;
    cin >> a[i];
  }else for(int i=0; i<n; i++){
    b[i] = (i/2)*2+1;
    cin >> a[i];
  }
  sort(a,a+n);
  for(int i=0; i<n; i++){
    if(a[i]!=b[i]){
      cout << 0 << endl;
      return 0;
    }
  }
  long long int ans=1;
  for(int i=0; i<n/2; i++){
    ans *= 2;
    ans %= 1000000007;
  }
  cout << ans << endl;
  
  return 0;
}

