#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long a,b;
  cin>>a;
  b=0;
  vector<long long>vecA(2*a);
  for(long long i=0;i<a*2;i++){
    cin>>vecA.at(i);
  }
  for(int k=2*a-1;k>0;k-=2){
    long long c=vecA.at(k);
    long long d=vecA.at(k-1)+b;
    if(d%c==0){
    }
    else{
      b+=c-d%c;
    }
  }
  cout<<b<<endl;
}