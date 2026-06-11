#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  vector<int> rate(9,0);
  for(int i=0;i<n;i++){
    if(a[i]<=3199){
      ++rate[a[i]/400];
    }else{
      ++rate[8];
    }
  }
  int min1=0;
  for(int i=0;i<8;i++){
    if(rate[i]!=0){
      min1+=1;
    }
  }
  int max1=min1+rate[8];
  min1=max(1,min1);
  cout<<min1<<" "<<max1<<endl;
  return 0;
}