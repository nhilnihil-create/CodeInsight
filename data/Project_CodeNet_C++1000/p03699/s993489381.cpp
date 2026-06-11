#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const ll INFS=1e18;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};
 
int main() {
  int n;
  cin>>n;
  vector<int> s(n);
  vector<int> m;
  rep(i,n) cin>>s[i];
  rep(i,n){
    if(s[i]%10!=0){
      m.push_back(s[i]);
    }
  }
  sort(all(m));
  sort(all(s));
  int sum=0;
  rep(i,n) sum+=s[i];
  if(sum%10!=0){
    cout<<sum<<endl;
    return 0;
  }
  else{
    if(m.size()==0){
      cout<<0<<endl;
    }
    else{
      cout<<sum-m[0]<<endl;
    }
  }
}