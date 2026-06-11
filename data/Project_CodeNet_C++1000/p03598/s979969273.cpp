#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  int n,k;
  cin>>n>>k;
  int ans=0;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    ans+=x<abs(x-k)?2*x:2*abs(x-k);
  }
  cout<<ans<<endl;
}