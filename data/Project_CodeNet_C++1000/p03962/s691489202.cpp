#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{

  ll a,b,c;
  cin>>a>>b>>c;
  if(a==b&&b==c){
    cout<<1<<endl;
  }else if(a==b||b==c||a==c){
    cout<<2<<endl;
  }else{
    cout<<3<<endl;
  }
  return 0;
}
