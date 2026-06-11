#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int X,Y;
  cin>>X>>Y;
  string ans="No";
  int A[]={0,1,3,1,2,1,2,1,1,2,1,2,1};
  if(A[X]==A[Y])ans="Yes";
  cout<<ans<<endl;
}