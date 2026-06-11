#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main() {
  int n,l;
  cin>>n>>l;
  vector<string> s(n);
  rep(i,n) cin>>s[i];
  sort(all(s));
  rep(i,n){
    cout<<s[i];
  }
  cout<<endl;
}