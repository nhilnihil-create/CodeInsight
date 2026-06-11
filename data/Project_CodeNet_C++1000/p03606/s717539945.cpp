#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n;
  cin>>n;
  int ans=0;
  rep(i,0,n){
    int l,r;
    cin>>l>>r;
    ans+=r-l+1;
  }
  cout<<ans<<endl;
}