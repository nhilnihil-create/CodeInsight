#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{

  ll n,s[110];
  ll max=0;
  cin>>n;
  rep(i,n){
    cin>>s[i];
    max+=s[i];
  }

  if(max%10!=0){
    cout<<max<<endl;
    return 0;
  }

  sort(s,s+n);
  rep(i,n){
    if(s[i]%10!=0){
      cout<<max-s[i]<<endl;
      return 0;
    }
  }

  cout<<0<<endl;
  return 0;
}
