#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int N;
  cin>>N;
  int A[8];
  int over=0;
  rep(i,8)A[i]=0;
  rep(i,N){
    int C;
    cin>>C;
    if(C<400)A[0]+=1;
    if(C>=400&&C<800)A[1]+=1;
    if(C>=800&&C<1200)A[2]+=1;
    if(C>=1200&&C<1600)A[3]+=1;
    if(C>=1600&&C<2000)A[4]+=1;
    if(C>=2000&&C<2400)A[5]+=1;
    if(C>=2400&&C<2800)A[6]+=1;
    if(C>=2800&&C<3200)A[7]+=1;
    if(C>=3200)over+=1;
  }
  int ans=0,minans=0,maxans=0;
  rep(i,8){
    if(A[i]!=0)ans+=1;
  }
  minans=ans;
  if(minans==0&&over>=1)minans=1;
  maxans=ans+over;
  cout<<minans<<" "<<maxans<<endl;
}