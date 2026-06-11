#include <bits/stdc++.h>
using namespace std;

int main(){
  int K,T;
  cin>>K>>T;
  int a[T];
  for(int i=0;i<T;i++){
    cin>>a[i];
  }
  sort(a,a+T);
  int d=a[T-1];
   if(d>K-d+1){
    cout<<d-(K-d)-1<<endl;
    return 0;
  }
  cout<<0<<endl;
  return 0;
}
