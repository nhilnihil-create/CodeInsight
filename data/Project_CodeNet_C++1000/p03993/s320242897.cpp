#include<bits/stdc++.h>
using namespace std;


int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  int ans=0;
  for(int i=0;i<n;++i){
    cin >> a[i];
    a[i]--;
  }
  for(int i=0;i<n;++i){
    int tmp=a[i];
    if(tmp>i && a[tmp]==i) ans++;
  }
  cout << ans << endl;
  return 0;
}
