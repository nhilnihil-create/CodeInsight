#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n;
  cin>>n;
  int vec[n],vecb[n];
  for(int i=0;i<n;i++){
    cin>>vec[i];
    vecb[i]=vec[i];
  }
  sort(vecb,vecb+n);
  map<int,int> ma;
  for(int i=0;i<n;i++){
    ma[vecb[i]]=i%2;
  }
  int ans=0;
  for(int i=0;i<n;i++){
    if(ma[vec[i]]!=i%2){
      ans++;
    }
  }
  cout<<ans/2<<endl;
  return 0;
}