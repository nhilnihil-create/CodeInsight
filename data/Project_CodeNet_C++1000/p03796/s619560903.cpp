#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{

  ll n,div=pow(10,9)+7,ans=1;;
  cin>>n;

  reps(i,n+1){
    ans*=i;
    ans%=div;
  }

  cout<<ans<<endl;
  return 0;
}
