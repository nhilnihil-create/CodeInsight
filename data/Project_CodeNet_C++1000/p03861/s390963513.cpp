#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{
  ll a,b,x;
  cin>>a>>b>>x;

  if(a==0){
    cout<<b/x+1<<endl;
  }else{
    cout<<b/x-(a-1)/x<<endl;
  }
  return 0;
}
