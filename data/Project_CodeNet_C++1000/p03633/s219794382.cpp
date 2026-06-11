#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;cin>>N;
  //vector<long> T(N);
  queue<long> A;
  for(int i=0;i<N;i++){
    long T;cin>>T;
    A.push(T);
  }
  while(A.size()>1){
    long X=A.front();
    A.pop();
    long Y=A.front();
    A.pop();
    long Z=(X/gcd(X,Y))*Y;
    A.push(Z);
  }
  cout<<A.front()<<endl;
}
  