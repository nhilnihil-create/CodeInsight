#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a,b;
  cin>>a>>b;
  if(a<=0&&0<=b){
    cout<<"Zero"<< endl;
    return 0;
  }
  long long x=0;
  for(long long i=a;i<=b;i++){
    if(i<0){
      x++;
    }
  }
  if(x%2==0){
    cout<<"Positive"<< endl;
  }
  else{
    cout<<"Negative"<< endl;
  }
}
