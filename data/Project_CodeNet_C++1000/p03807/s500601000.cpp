#include<bits/stdc++.h>
using namespace std;
int main(){
  long n;
  cin>>n;
  vector<long> a(n);
  for(long i=0;i<n;i++){
    cin>>a[i];
  }
  int odd=0;
  for(long i=0;i<n;i++){
    if(a[i]%2==1){
      odd++;
    }
  }
  if(odd%2==1){
    cout<<"NO"<<endl;
  }
  else{
    cout<<"YES"<<endl;
  }
}