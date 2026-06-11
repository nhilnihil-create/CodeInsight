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

int main(){
  ll q,h,s,d,n;
  cin>>q>>h>>s>>d>>n;
  ll ans;
  if(n%2==0){
    ans=min(q*8,min(h*4,min(s*2,d)))*(n/2);
  }
  if(n%2==1){
    ans=min(q*8,min(h*4,min(s*2,d)))*(n/2)+min(q*4,min(h*2,s));
  }
  cout<<ans<<endl;
}