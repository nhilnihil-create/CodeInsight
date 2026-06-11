#include<bits/stdc++.h>
using namespace std;
#define P 1000000007
long perm(long x){
  return (x==0?1:perm(x-1)*x%P);
}
int main(){
  long N,M;cin>>N>>M;
  if(abs(N-M)>1){cout<<0<<endl;return 0;}
  cout<<perm(N)*perm(M)*((N==M)+1)%P;
}

