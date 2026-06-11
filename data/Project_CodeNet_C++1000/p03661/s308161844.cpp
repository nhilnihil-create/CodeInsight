#include <bits/stdc++.h>
using namespace std;
int main(){
  long long N, b=0;
  cin >>N;
  vector<long long> A(N,0), B(N,0);
  for(int i=0; i<N; i++){
    long long a;
    cin >>a;
    b+=a;
    A[i]=a;
    B[i]=b;
  }
  long long ans=1e15;
  for(int i=0; i<N-1; i++){
    ans=min(abs(B[N-1]-2*B[i]), ans);
  }
  cout <<ans <<endl;
}
