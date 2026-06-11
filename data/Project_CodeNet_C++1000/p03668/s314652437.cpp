#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> G[100100];
bool ok[100100];
int dfs(int n){
  int ans=0;
  ok[n]=false;
  for(int i:G[n])
    if(ok[i])ans^=dfs(i);
  return ans+1;
}
signed main(){
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
    int a,b;
    cin>>a>>b;
    G[a-1].push_back(b-1);
    G[b-1].push_back(a-1);
  }
  for(int i=0;i<N;i++)ok[i]=true;
  ok[0]=false;
  puts(dfs(0)-1?"Alice":"Bob");
}