#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{
  int n;
  cin>>n;
  int a[8]={1,2,4,8,16,32,64};
  int ans=0;
  rep(i,7){
    if(a[i]<=n&&a[i]>ans){
      ans=a[i];
    }
  }
  cout<<ans<<endl;
  return 0;
}
