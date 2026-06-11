#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef pair<ll,ll> P;
using VP = vector<P>; using VVP = vector<VP>;
using VI = vector<ll>; using VVI = vector<VI>; using VVVI = vector<VVI>;
const int inf=1e9+7;
const ll INF=1LL<<58;
const ll mod=1e9+7;

int main(){
  int i,j,k;
  int n;
  cin>>n;
  string s;
  cin>>s;
  VI v(n);
  for(i=0;i<2;i++){
    for(j=0;j<2;j++) {
      v[0]=i;
      v[1]=j;
      for(k=2;k<n;k++) {
        int cnt=v[k-1]+v[k-2];
        if(s[k-1]=='x') cnt++;
        if(cnt%2==0) v[k]=0;
        else v[k]=1;
      }
      int u1=v[0]+v[1]+v[n-1];
      int u2=v[0]+v[n-1]+v[n-2];
      if(s[0]=='x') u1++;
      if(s[n-1]=='x') u2++;
      if(u1%2==0&&u2%2==0){
        for(k=0;k<n;k++){
          cout<<((v[k]==0) ? "S" : "W"); 
        }
        cout<<endl;
        return 0;
      }
    } 
  }
  cout<<-1<<endl;
  return 0;
  
  return 0;
}