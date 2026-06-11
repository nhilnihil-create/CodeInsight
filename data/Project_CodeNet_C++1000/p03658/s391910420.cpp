#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n,k,l;
  cin>>n>>k;
  vector<int> rod(n);
  for(int i=0;i<n;i++){
    cin>>l;
    rod.push_back(l);
  }
  int ans=0;
  sort(rod.rbegin(),rod.rend());
  for(int i=0;i<k;i++){
    ans+=rod[i];
  }
  cout<<ans<<endl;
  return 0;
}