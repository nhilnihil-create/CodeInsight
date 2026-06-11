#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{
  int n;
  cin>>n;
  int a[100010];
  int sum=0;
  rep(i,n){
    cin>>a[i];
    sum+=a[i];
  }
  if(sum%2==0){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
  return 0;
}
