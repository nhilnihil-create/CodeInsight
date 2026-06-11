#include<bits/stdc++.h>
using namespace std;
int main(){
  long long n,p;
  cin >> n >> p;
  long long a[n];
  for(int i=0;i<n;i++){
    cin >> a[i];
    if(a[i]%2==1){
      cout << (long long)pow(2,n-1);
      return 0;
    }
  }
  if(p==0)cout << (long long)pow(2,n);
  else cout << 0;
}
