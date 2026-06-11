#include <iostream>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;

int m,sz,cnt;
ll n;
vector<int> v[100001];
int used[100001];
bool ok;

void dfs(int x){
  sz++;
  rep(i,v[x].size()){
    if(used[v[x][i]]==0){
      used[v[x][i]]=-used[x];
      dfs(v[x][i]);
      }
    else if(used[v[x][i]]==used[x])ok=false;
    }
  }
  
int main(){
  cin>>n>>m;
  rep(i,m){
    int l,r;
    cin>>l>>r;
    l--;r--;
    v[l].push_back(r);
    v[r].push_back(l);
    }
  rep(i,n)used[i]=0;
  ll cycle,line,point;
  cycle=line=point=0;
  rep(i,n){
    if(used[i]==0){
      sz=0;ok=true;
      used[i]=1;
      dfs(i);
      if(sz==1)point++;
      else if(ok)line++;
      else cycle++;
      }
    }
  cout<<(cycle+line)*(cycle+line)+line*line+2*n*point-point*point<<endl;
  return 0;
} 
