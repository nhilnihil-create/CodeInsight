#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  long long int ans=1;
  cin >> n;
  for(int i=2;i<=n;++i){
    ans=ans*i%1000000007;
  }
  cout<<ans<<endl;
}