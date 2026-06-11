#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int i,ans=0;
  for(i=1;i<=n;i++){
    ans+=i;
  }
  cout << ans;
}