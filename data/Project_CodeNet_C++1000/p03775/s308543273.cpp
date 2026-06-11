#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  ll n;
  cin>>n;
  int rn=sqrt(n);
  int max=1;
  for(int i=1;i<=rn;i++) if(n%i==0) max=i;
  max=n/max;
  int ans=1;
  while(max/10!=0){
    ans++;
    max/=10;
  }
  cout << ans;
}