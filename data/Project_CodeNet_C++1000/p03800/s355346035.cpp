#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll> P;
#define pb push_back
#define mp make_pair
#define fr(i,n) for(int i=0;i<n;i++)
#define Fr(i,n) for(int i=0;i++<n;)
#define ifr(i,n) for(int i=n-1;i>=0;i--)
#define iFr(i,n) for(int i=n;i>0;i--)

bool nw(bool f1,bool f2,char c){
  if(c=='o'^f2) return 1-f1;
  else return f1;
}

int main(){
  int n;
  string s;
  cin>>n>>s;
  bool f[100010];
  f[1]=0;f[2]=0;
  Fr(i,n-2) f[i+2]=nw(f[i],f[i+1],s[i]);
  if(nw(f[n-1],f[n],s[n-1])==f[1]&&nw(f[n],f[1],s[0])==f[2]){
    Fr(i,n) cout<<(f[i]?'S':'W');
    return 0;
  }
  f[1]=0;f[2]=1;
  Fr(i,n-2) f[i+2]=nw(f[i],f[i+1],s[i]);
  if(nw(f[n-1],f[n],s[n-1])==f[1]&&nw(f[n],f[1],s[0])==f[2]){
    Fr(i,n) cout<<(f[i]?'S':'W');
    return 0;
  }
  f[1]=1;f[2]=0;
  Fr(i,n-2) f[i+2]=nw(f[i],f[i+1],s[i]);
  if(nw(f[n-1],f[n],s[n-1])==f[1]&&nw(f[n],f[1],s[0])==f[2]){
    Fr(i,n) cout<<(f[i]?'S':'W');
    return 0;
  }
  f[1]=1;f[2]=1;
  Fr(i,n-2) f[i+2]=nw(f[i],f[i+1],s[i]);
  if(nw(f[n-1],f[n],s[n-1])==f[1]&&nw(f[n],f[1],s[0])==f[2]){
    Fr(i,n) cout<<(f[i]?'S':'W');
    return 0;
  }
  cout<<-1<<endl;
}