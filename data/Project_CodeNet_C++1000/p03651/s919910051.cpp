#include <bits/stdc++.h>
using namespace std;

int gcd(long long a, long long b) {
  if(a < b) return gcd(b, a);
     if (b == 0) return a;
    else return gcd(b, a % b);
}
  
int main(){
  int N,K;
  cin>>N>>K;
  int A[N];
  cin>>A[0];
  int GCD=A[0];
  int amax=A[0];
  for(int i=1;i<N;i++){
    cin>>A[i];
    GCD=gcd(GCD,A[i]);
    amax=max(amax,A[i]);
  }
  
  //cout<<GCD<<" "<<amax<<endl;
  if(K%GCD==0 && K<=amax){
    cout<<"POSSIBLE"<<endl;
    return 0;
  }
  cout<<"IMPOSSIBLE"<<endl;
  return 0;
}
