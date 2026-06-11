#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{

  ll a,b;
  cin>>a>>b;
  if(a==13&&b==1)a=0;
  if(a==1&&b==13)b=0;
  if(a>b){
    cout<<"Alice"<<endl;
  }else if(a<b){
    cout<<"Bob"<<endl;
  }else{
    cout<<"Draw"<<endl;
  }


  return 0;
}
