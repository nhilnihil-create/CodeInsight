#include<bits/stdc++.h>
using namespace std;
int v[200001];
int main(){
  int n,ans=0;
  cin >> n;

  for(int i=1;i<=n;i++){
    int a;
    cin >> a;
    v[a]++;
  }
  for(int i=-1;i<=100001;i++)ans=max(ans,v[i]+v[i-1]+v[i+1]);
  cout << ans << endl;
}
