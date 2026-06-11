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
  vector<int> a(n);
  rep(i, n)cin>>a[i];

  sort(a.begin(), a.end());
  bool all_same = true;
  rep(i, n-1)if(a[i]!=a[i+1])all_same=false;

  if(all_same){
    if(a[0]==n-1 || a[0]==1 || a[0]*2<=n)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
  }

  map<int, int>m;
  rep(i, n)m[a[i]]++;
  if(m.size()>2) { cout<<"No"<<endl; return 0;}
  if(a.back()-a[0]>1) { cout<<"No"<<endl; return 0; }


  if(m[a.back()]==(n-a.back())*2 &&  n-((n-a.back())*2)==m[a[0]])cout<<"Yes"<<endl;
  else cout<<"No"<<endl;

  return 0;
}