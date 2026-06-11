#include <iostream>
#include <queue>
#include<algorithm>
using namespace std;

int main(){
  long long n,i,j,k,sum=0;
  cin >> n;
  long long a[3*n+10],ret[n+1]={};
  for(i=0;i<3*n;i++){
    cin >> a[i];
  }
  priority_queue<long long> p,q;
  for(i=0;i<n;i++){
    sum+=a[i];
    p.push(-a[i]);
  }
  ret[0]=sum;
  for(i=n;i<2*n;i++){
    sum+=a[i];
    p.push(-a[i]);
    sum+=p.top();
    p.pop();
    ret[i-n+1]=sum;
  }

  sum=0;
  for(i=0;i<n;i++){
    sum+=a[3*n-i-1];
    q.push(a[3*n-i-1]);
  }
  ret[n]-=sum;
  for(i=2*n-1;i>=n;i--){
    sum+=a[i];
    q.push(a[i]);
    sum-=q.top();
    q.pop();
    ret[i-n]-=sum;
  }
  long long ans=ret[0];
  for(i=0;i<=n;i++){
    ans=max(ans,ret[i]);
  }
  cout << ans << endl;
  return 0;
}
