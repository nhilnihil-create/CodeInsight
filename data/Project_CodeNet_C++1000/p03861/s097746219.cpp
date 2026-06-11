#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

int dec(int L,int M){
  if(L==-1)return 0;
  return L/M+1;
}

signed main(){
  int A,B,X;
  cin>>A>>B>>X;
  cout<<dec(B,X)-dec((A-1),X)<<endl;
  return 0;
}