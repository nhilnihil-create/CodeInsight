#include <bits/stdc++.h>
using namespace std;
int main(){
  long long a,b;
  cin>>a>>b;
  if(a<=0 && b>=0){
    cout<<"Zero"<<endl;
    return 0;
  }
  if(a<=0 && b<0 && (b-a+1)%2==1){
    cout<<"Negative"<<endl;
    return 0;
  }
  else{
    cout<<"Positive"<<endl;
  }
  return 0;
}