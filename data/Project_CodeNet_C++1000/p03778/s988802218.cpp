#include<bits/stdc++.h>
using namespace std;
int main(){
  int W; int A; int B;
  cin>>W>>A>>B;
  int L=max(A,B);
  int R=min(A+W,B+W);
  if(L-R>=0)
    cout<<L-R<<endl;
  else cout<<0<<endl;
}
