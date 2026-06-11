#include<bits/stdc++.h>
using namespace std;
int main(){
  long long n;
  cin >> n;
  long long a[2*n];
  for(long long i=0;i<2*n;i++){
    cin >> a[i];
  }
  sort(a,a+2*n);
  long long ans=0;
  for(long long i=0;i<2*n;i=i+2){
    ans=ans+min(a[i],a[i+1]);
  }
  cout << ans;
}
