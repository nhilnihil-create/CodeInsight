#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){

  int N;
  cin>>N;
  vector<int>a(3*N);
  for(int i=0;i<=3*N-1;i++){
  
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  long long int ans=0;
  int count=0;
  for(int i=3*N-2;i>=0;i-=2){
  
    ans+=a[i];
    count++;
    if(count==N)break;
  }
  cout<<ans;
  return 0;
}