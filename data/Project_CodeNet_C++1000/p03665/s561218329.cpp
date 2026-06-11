#include <bits/stdc++.h>
using namespace std;
long long RepeatSquaring(long long N, long long P){
    if (P == 0) return 1;
    if (P % 2 == 0) {
        long long t = RepeatSquaring(N, P / 2);
        return t * t;
    }
    return N * RepeatSquaring(N, P - 1);
}
int main(){
  int N,P;cin>>N>>P;
  for(int i=0;i<N;i++){
    int a;cin>>a;
    if(a%2==1){
      cout<<RepeatSquaring(2,N-1)<<endl;
      return 0;
    }
  }
  if(P==0)cout<<RepeatSquaring(2,N)<<endl;
  else puts("0");
}