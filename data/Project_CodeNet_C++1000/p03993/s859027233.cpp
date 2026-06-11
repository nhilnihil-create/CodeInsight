#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin>>n;
  map<int,int> suki;
  for(int i=1; i<=n; i++){
    int a;
    cin>>a;
    suki[i]=a;
  }
  int ans=0;
  for(int i=1; i<=n; i++){
    if(i==suki[suki[i]]){
      ans++;
    }
  }
  ans/=2;
  cout<<ans<<endl;
}