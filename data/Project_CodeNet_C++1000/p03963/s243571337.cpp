#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{
  ll n,k;
  cin>>n>>k;

  cout<<k*(ll)pow(k-1,n-1)<<endl;
  return 0;
}
