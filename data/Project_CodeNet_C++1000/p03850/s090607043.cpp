#include<iostream>
#include<algorithm>
#include<vector>
#include<complex>
using namespace std;
#define chmax(a,b) a=max(a,b);
typedef long long ll;
typedef pair<ll,ll> P;
#define N 100010
vector<ll> v;
ll n,s[N];
int main(){
  cin>>n; char op='+';
  ll befpo=-1;
  for(int i=0;i<n;i++){
    if(i)cin>>op; ll a;cin>>a;
    if(op=='+'){
      if(~befpo)befpo+=a;
      else befpo=a;
    }
    else{
      if(~befpo)v.push_back(befpo); befpo=-1;
      v.push_back(-a);
    }
  }if(~befpo)v.push_back(befpo);
  n=v.size(); s[n]=0;
  for(int i=n-1;i>=0;i--){
    s[i]=s[i+1]+abs(v[i]);
  }
  //for(int i=0;i<n;i++)cout<<v[i]<<" ";cout<<endl;
  ll ans=-1e17,sum=0;
  for(int i=0;i<n-1;i++){
    sum+=v[i];
    if(v[i]>0)continue;
    chmax(ans,sum+-v[i+1]+s[i+2]);
  }
  sum+=v[n-1]; chmax(ans,sum);
  cout<<ans<<endl;
    return 0;
}

