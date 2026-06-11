#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> arr(3*n);
  for(int i=0;i<3*n;i++){
      cin >>arr.at(i);
  }
  sort(arr.begin(),arr.end());
  reverse(arr.begin(),arr.end());
  int64_t sum=0;
  for(int i=1;i<2*n;i+=2){
    sum+=arr.at(i);
  }
  cout<<sum;
  return 0;
}