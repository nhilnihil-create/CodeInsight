#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int X,A,B;
  cin>>X>>A>>B;
  if(abs(A-X)>=abs(B-X))cout<<"B"<<endl;
  else cout<<"A"<<endl;
  return 0;
} 