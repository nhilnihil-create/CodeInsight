#include<iostream>
#include<vector>
using namespace std;

int main(){
  int n;cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  vector<int> v(1e5+1,0);
  for(int i=0;i<n;i++){
    v[a[i]]++;
  }
  int cnt=0;
  for(int i=0;i<1e5+1;i++)if(v[i]>1){
    cnt+=v[i]-1;
  }
  cout<<n-((cnt+1)/2)*2<<endl;
  return 0;
}