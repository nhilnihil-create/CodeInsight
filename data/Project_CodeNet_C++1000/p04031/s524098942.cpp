#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++){
    cin>>a.at(i);
  }
  sort(a.begin(),a.end());
  int ans=100000000;
  for(int i=a.at(0);i<=a.at(n-1);i++){
    int tmp=0;
    for(int j=0;j<n;j++){
      tmp+=(a.at(j)-i)*(a.at(j)-i);
    }
    ans=min(ans,tmp);
  }
  cout <<ans<<endl;
}