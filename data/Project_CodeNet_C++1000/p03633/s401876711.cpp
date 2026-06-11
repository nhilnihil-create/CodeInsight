#include<bits/stdc++.h>
using namespace std;

long long GCD(long long a, long long b){
  
  long long r=a%b;
  while(r!=0){
    a=b;
    b=r;
    r=a%b;
  }
  return b;
}

int main(){

  long long N, KB, t, i;
  cin>>N;
  cin>>KB;
  for(i=0;i<N-1;i++){
    cin>>t;
    KB=KB*(t/GCD(KB,t));
  }
  cout<<KB<<endl;
  return 0;
}