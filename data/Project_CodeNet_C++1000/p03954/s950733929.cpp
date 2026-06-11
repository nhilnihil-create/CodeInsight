#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll N;
int main(){
  cin>>N;
  vector<ll>a(2*N-1);
  for(int i=0;i<2*N-1;i++)
    cin>>a[i];
  ll left=1;ll right=2*N-1;
  vector<ll>b(2*N-1);
  while(1<right-left){
    ll mid=left+(right-left)/2;
    for(int i=0;i<2*N-1;i++)
    if(mid<=a[i])b[i]=1;else b[i]=0;
    ll x=-1;ll y=-1;
    for(int i=N-1;i<2*N-2;i++){
      if(b[i]==b[i+1]){y=i;break;}
    }for(int i=N-1;0<i;i--){
    if(b[i]==b[i-1]){x=i;break;}
    }if(x==-1 && y==-1){
    if((N%2==0 && b[N-1]==1)|| (N%2==1 && b[N-1]==0))
      right=mid;
      else
        left=mid;
    }else if(x!=-1 && y==-1){
    if(b[x]==1)left=mid;else right=mid;
    }else if(x==-1 && y!=-1){
    if(b[y]==1)left=mid;else right=mid;
    }else{
    if(y+x<=2*N-2){
    if(b[y]==1)left=mid;else right=mid;
    }else{
    if(b[x]==1)left=mid;else right=mid;
    }
    }
  }cout<<left<<endl;
  return 0;
}