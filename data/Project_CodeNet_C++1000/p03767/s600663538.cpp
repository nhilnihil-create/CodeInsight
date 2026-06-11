#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N;
  cin>>N;
  long long sum=0;
  long long count=0;
  priority_queue<long long> power;
  for(long long i=0; i<3*N; i++){
    long long a;
    cin>>a;
    power.push(a);
  }
  while(count<N){
    count++;
    power.pop();
    sum+=power.top();
    power.pop();
  }
  cout<<sum<<endl;
}
