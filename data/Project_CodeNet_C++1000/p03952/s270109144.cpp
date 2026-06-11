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

  vector<int> r;
  rep1(i, c)r.push_back(i);
  swap(r[n-1], r[x-1]);
//  for(int p: r)cout<<p<<' ';cout<<endl;
  swap(r[n-2], r[0]);
//  for(int p: r)cout<<p<<' ';cout<<endl;
  swap(r[n], r[c-1]);
  for(int p: r)cout<<p<<' ';

  return 0;
}
