#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll num[100005]={0};
int main(){
  ll n,sum=0;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>num[i];
    sum+=num[i];
  }
  ll kn=n*(n+1)/2;
  if(sum%kn!=0){
    cout<<"NO"<<endl;
    return 0;
  }
  ll kai=sum/kn;
  for(int i=0;i<n;i++){
    int nxt=(i+1)%n;
    ll del=num[nxt]-num[i]-kai;
    if(del>0){
      cout<<"NO"<<endl;
      return 0;
    }
    del*=-1;
    if(del%n!=0){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;
  return 0;
}
