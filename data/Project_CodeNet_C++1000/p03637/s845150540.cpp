#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(void){
  int n;
  cin>>n;
  vector<ll> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int count=0;
  int count2=0;
  for(int i=0;i<n;i++){
    if(a[i]%4==0){
      ++count2;
    }
    if(a[i]%2==0){
      ++count;
    }
  }
  count-=count2;
  if(count>=n-count2*2 | count2>=n/2){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}