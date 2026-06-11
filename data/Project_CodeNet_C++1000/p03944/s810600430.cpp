#include <bits/stdc++.h>
using namespace std;
int main(){
  int W,H,N; cin>>W>>H>>N;
  int A=0,B=W,C=0,D=H;
  for(int i=0;i<N;i++){
    int a,b,c; cin>>a>>b>>c;
    if(c==1)A=max(A,a);
    else if(c==2)B=min(B,a);
    else if(c==3)C=max(C,b);
    else D=min(D,b);
  }
  cout<<max(B-A,0)*max(D-C,0)<<endl;
}
