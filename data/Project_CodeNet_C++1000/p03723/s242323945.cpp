#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int A,B,C;
  cin>>A>>B>>C;
  int i=0;
  for(;A%2==0 && B%2==0 && C%2==0;i++){
    int a=(B+C)/2,b=(A+C)/2,c=(A+B)/2;
    A=a,B=b;C=c;
    if(i>=30){
      cout<<-1<<endl;
      return 0;
    }
  }
  cout<<i<<endl;
}