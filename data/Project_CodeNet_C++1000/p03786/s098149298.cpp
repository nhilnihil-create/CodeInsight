#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n;
  cin>>n;
  ll vec[n],sum[n];
  for(int i=0;i<n;i++){
    cin>>vec[i];
  }
  sort(vec,vec+n);
  sum[0]=vec[0];
  for(int i=1;i<n;i++){
    sum[i]=sum[i-1]+vec[i];
  }
  for(int i=n-1;i>=0;i--){
    if(sum[i-1]*2<vec[i]){
      cout<<n-i<<endl;
      return 0;
    }
  }
  cout<<n<<endl;
  return 0;
}