#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MAX 300003
#define MOD 1000000007
#define INF 1000000000000000000
using Graph=vector<vector<int>>;

int dfs(Graph &G,int v){
  int n=G.at(v).size();
  if(n==0){
    return 0;
  }
  vector<int> count(n);
  for(int i=0;i<n;i++){
    count.at(i)=dfs(G,G.at(v).at(i));
  }
  sort(count.begin(),count.end());
  int ans=count.at(0)+n;
  for(int i=1;i<n;i++){
    ans=max(count.at(i)+n-i,ans);
  }
  return ans;
}

int main(){
  int N;
  cin>>N;
  Graph G(N);
  for(int i=1;i<N;i++){
    int a;
    cin>>a;
    a--;
    G.at(a).push_back(i);
  }
  cout<<dfs(G,0)<<endl;
}
