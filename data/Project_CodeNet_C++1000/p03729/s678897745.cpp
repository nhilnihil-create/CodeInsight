#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  string A,B,C;
  cin>>A>>B>>C;
  if(A[A.size()-1]==B[0]&&B[B.size()-1]==C[0])cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}