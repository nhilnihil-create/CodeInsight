#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{
  int n;
  int max=0;
  int ans=0;
  cin>>n;
  reps(i,n+1){
    int count=0;
    int tmp=i;
    while(tmp>0){
      tmp/=2;
      count++;
    }
    if(count>max){
      ans=i;
      max=count;
    }
  }

  cout<<ans<<endl;
  return 0;
}
