#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  int a[N];
  for(int i=0;i<N;i++){
    cin>>a[i];
  }
  int p=0,s=0,ss=0;
  for(int i=0;i<N;i++){
    if(a[i]%4==0){
      ss++;
    }
    else if(a[i]%2==0){
      s++;
    }
    else{
      p++;
    }
  }
  
  string ans="No";
  
  if(ss>=N/2){
    ans="Yes";
  }
  if(ss>=p){
    ans="Yes";
  }
  cout<<ans<<endl;
}
