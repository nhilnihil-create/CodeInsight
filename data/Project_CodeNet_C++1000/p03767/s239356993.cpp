#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;
using namespace std;
int main()
{
  int n;
  cin>>n;
  ll a[400000];
  rep(i,3*n)cin>>a[i];
  sort(a,a+3*n,greater<int>());

  ll sum=0;
  int count=0;
  int start=1;
  while(count<n){
    sum+=a[start];
    start+=2;
    count++;
  }

  cout<<sum<<endl;
  return 0;
}
