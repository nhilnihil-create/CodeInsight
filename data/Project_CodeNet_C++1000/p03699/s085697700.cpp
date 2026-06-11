#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int>a(n);
  for(int i=0;i<n;i++)
    cin >> a.at(i);
  sort(a.begin(),a.end());
  int ans=0;
  bool ok=false;
  for(int i=0;i<n;i++)
    ans+=a.at(i);
  if(ans%10==0){
    for(int i=0;i<n;i++){
      if(a.at(i)%10!=0){
        ans-=a.at(i);
        ok=true;
        break;
      }
    }
    if(!ok)
      ans=0;
  }
  cout << ans << endl;
  return 0;
}