#include <bits/stdc++.h>
using namespace std;
int main(){
  long long N,A,B; cin>>N>>A>>B;
  if((N==1&&A!=B)||A>B){cout<<0<<endl; return 0;}
  if(N==1){cout<<1<<endl; return 0;}
  cout<<B*(N-1)+A-A*(N-1)-B+1<<endl;
}