#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{
  ll a,b,c;
  cin>>a>>b>>c;
  reps(i,b+1){
    if((a*i)%b==c){
      cout<<"YES"<<endl;
      return 0;
    }
  }
  cout<<"NO"<<endl;
  return 0;
}
