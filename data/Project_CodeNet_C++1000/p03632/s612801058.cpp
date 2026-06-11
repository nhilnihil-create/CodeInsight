#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,D;cin>>A>>B>>C>>D;
  int P=max(A,C);
  int Q=min(B,D);
  if(P>Q) cout<<0<<endl;
  else cout<<Q-P<<endl;
}