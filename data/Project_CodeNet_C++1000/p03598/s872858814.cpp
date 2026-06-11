#include <bits/stdc++.h>
using namespace std; 
int main() {
  int N;
  int K;
  int i=0;
  int sum=0;
  cin>>N>>K;
  while(i<N){
    int a;
    cin>>a;
    if(a>=K-a){
      sum=sum+2*K-2*a;
    }else{
      sum+=2*a;
    }
    i++;
  }
    cout<<sum<<endl;

}
