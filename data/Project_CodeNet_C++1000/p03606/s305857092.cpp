#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,a,b,sum;
  sum=0;
  cin>>N;
  while(N>0){
    cin>>a>>b;
    sum +=b-a+1;
    N--;
  }
  cout<<sum<<endl;
}