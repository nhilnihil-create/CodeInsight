#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n;
  cin>>n;
  int a[n];
  rep(i,0,n) cin>>a[i];
  sort(a,a+n);
  int sum=0;
  rep(i,0,n) sum+=a[i];
  if(sum%10!=0) cout<<sum<<endl;
  else{
    int i=0;
    while(i<n && a[i]%10==0){
      i++;
    }
    if(i==n) cout<<0<<endl;
    else cout<<sum-a[i]<<endl;
  }
}