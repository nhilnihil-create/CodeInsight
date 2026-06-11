#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int>a(n);
  for(int i=0;i<n;i++)
    cin >> a.at(i);
  for(int i=0;i<n;i++)
    a.at(i)--;
  int ans=0;
  for(int i=0;i<n;i++){
    if(a.at(a.at(i))==i)
      ans++;
  }
  cout << ans/2 << endl;
  return 0;
}