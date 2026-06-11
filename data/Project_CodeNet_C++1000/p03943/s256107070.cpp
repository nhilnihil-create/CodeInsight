#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{

  ll a[3];
  cin>>a[0]>>a[1]>>a[2];
  sort(a,a+3,greater<int>());

  if(a[0]==a[1]+a[2]){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}
