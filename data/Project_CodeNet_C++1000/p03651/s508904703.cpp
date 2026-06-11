#include "bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define all(a) a.begin(),a.end()
typedef pair<int,int> P;
const long long mod=1000000007;
const long long inf=1ll<<61;
int a[100006];

int gcd(int a,int b){
  if(!b)return a;
  return gcd(b,a%b);
}

signed main(){
  int n,k;cin>>n>>k;
  rep(i,n)cin>>a[i];
  sort(a,a+n);
  int g=a[0];
  rep(i,n-1)g=gcd(g,a[i+1]);
  if(k<=a[n-1]&&(a[n-1]-k)%g==0)cout<<"POSSIBLE"<<endl;
  else cout<<"IMPOSSIBLE"<<endl;
}