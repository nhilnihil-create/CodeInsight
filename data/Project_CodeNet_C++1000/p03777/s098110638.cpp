#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  char A,B;
  cin>>A>>B;
  bool ch=true;
  if(A=='H'){
    if(B=='D')ch=false;
  }
  if(A=='D'){
    if(B=='H')ch=false;
  }
  if(ch)cout<<'H'<<endl;
  else cout<<'D'<<endl;
  return 0;
}