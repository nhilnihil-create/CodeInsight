#include<bits/stdc++.h>
using namespace std;
#define INF (1<<28)
#define DEKAI 1000000007
#define lp(i,n) for(int i=0;i<n;i++)
#define int long long


signed main(){
  int n;
  cin>>n;
  int a[100001];
  int sum=0;
  lp(i,n){
    cin>>a[i];
    sum+=a[i];
  }
  a[n]=a[0];
  int cnt=sum*2/((n+1)*n);
  double cnc=(double)sum*2/(double)((n+1)*n);
  if(cnt!=cnc){
    cout<<"NO"<<endl;
    return 0;
  }
  int ans=cnt;
  lp(i,n){
    int x=a[i+1]-a[i]-cnt;
    //cout<<x<<endl;
    if(x==0) continue;
    if((-1*x)%n!=0||x>0){
      cout<<"NO"<<endl;
      return 0;
    }
    ans+=x/n;
  }
  if(ans==0) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}