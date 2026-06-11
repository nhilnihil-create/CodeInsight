#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

int main(){
  int n, x;cin>>n>>x;
  int c = 2*n-1;
  if(x==1 || x==c){ cout<<"No"<<endl; return 0; }

  cout<<"Yes"<<endl;

  int f = 0;
  if(x<n)f=n+x-1;
  else if(x>n)f=x-n;

  rep(i, c)cout<<(i+f)%c+1<<' ';

  return 0;
}