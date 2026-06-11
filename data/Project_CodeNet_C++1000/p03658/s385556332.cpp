#include<bits/stdc++.h>
using namespace std;
 
int main() {
  int N,K,i;
  cin>>N>>K;
  int ans=0;

  int a[N];
  for (i=0;i<N;i++)cin>>a[i];
  sort(a,a+N);
  reverse(a,a+N);
  
  for (i=0;i<K;i++){
    ans += a[i];
  }
  cout << ans << endl;
}