#include<iostream>
using namespace std;
typedef long long ll;
ll num[100005]={0};
int main(){
  ll n,x;
  cin>>n>>x;
  for(int i=1;i<=n;i++) cin>>num[i];
  ll ok_l=0;
  for(int i=1;i<n;i++){
    if(num[i]+num[i+1]>=x) ok_l=i;
  }
  if(ok_l==0){
    cout<<"Impossible"<<endl;
    return 0;
  }
  cout<<"Possible"<<endl;
  for(int i=1;i<ok_l;i++) cout<<i<<endl;
  for(int i=n-1;i>ok_l;i--) cout<<i<<endl;
  cout<<ok_l<<endl;
}
