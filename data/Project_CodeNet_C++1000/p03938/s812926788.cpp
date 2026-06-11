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
  int n;cin>>n;
  vector<int> p(n);
  rep(i, n){ cin>>p[i]; p[i]--; }

  vector<ll>c(n, n+1);
  rep(i, n) c[p[i]]+=n*n+i+1;

  vector<ll>a(n), b(n);;
  rep(i, n)a[i]=i+1;
  rep(i, n)b[i]=c[i]-a[i];

  rep1(i, n-1){
    if(b[i-1]<=b[i]){
      ll d = b[i]-b[i-1]+1;
      for(int j=i; j<n; j++) { a[j]+=d; b[j]-=d; }
    }
  }

  ll md=0;
  for(auto c: b)md=min<ll>(md, c);
  rep(i, n)b[i]+=(1-md);

//  cout<<endl;
  rep(i, n)cout<<a[i]<<' ';cout<<endl;
  rep(i, n)cout<<b[i]<<' ';cout<<endl;
//  rep(i, n)cout<<a[i]+b[i]<<' ';cout<<endl;

  return 0;
}