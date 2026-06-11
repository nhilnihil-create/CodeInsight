#include<bits/stdc++.h>
using namespace std;
 
int main() {
  long long N,i;
  cin>>N;
  long long ans=0;
 
  long long a[3*N];
  for (i=0;i<3*N;i++)cin>>a[i];
  sort(a,a+3*N);
  reverse(a,a+3*N);
  
  for (i=0;i<N;i++){
    ans += a[2*i+1];
  }
  cout << ans << endl;
}