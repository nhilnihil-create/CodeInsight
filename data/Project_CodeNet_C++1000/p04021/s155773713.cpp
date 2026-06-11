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
  vector<int>a(n);
  rep(i, n)cin>>a[i];

  vector<int>ca(a);
  sort(ca.begin(), ca.end());
  set<int> s;
  rep(i, n){
    if(i%2==0)continue;
    s.insert(ca[i]);
  }

  int c=0;
  rep(i, n){
    if(i%2==0)continue;
    if(s.count(a[i])==0)c++;
  }

  cout<<c<<endl;

  return 0;
}