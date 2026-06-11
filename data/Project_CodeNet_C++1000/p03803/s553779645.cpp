#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int A,B;
  cin>>A>>B;
  if(A==1)A=14;
  if(B==1)B=14;
  if(A>B)cout<<"Alice"<<endl;
  if(B>A)cout<<"Bob"<<endl;
  if(A==B)cout<<"Draw"<<endl;
  return 0;
}