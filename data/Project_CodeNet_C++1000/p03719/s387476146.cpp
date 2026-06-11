#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{

  ll a,b,c;
  cin>>a>>b>>c;

  if(c>=a&&c<=b){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}
