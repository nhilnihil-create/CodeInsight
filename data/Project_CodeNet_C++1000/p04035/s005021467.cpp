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
  int n, l;cin>>n>>l;
  vector<int>a(n);
  rep(i, n)cin>>a[i];

  int last_knot = -1;
  rep(i, n-1)if(a[i]+a[i+1]>=l){
    last_knot=i;
    break;
  }

  if(last_knot==-1) { cout<<"Impossible"<<endl; return 0; }

  cout<<"Possible"<<endl;

  for(int i=0; i<last_knot; i++) cout<<i+1<<endl;
  for(int i=n-1; i>last_knot+1; i--) cout<<i<<endl;
  cout<<last_knot+1<<endl;

  return 0;
}