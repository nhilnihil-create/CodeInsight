#include<iostream>
#include<vector>
#include<algorithm> // sort,reverse
using namespace std;
#define df 0
int dfs(int v,vector<vector<int>> const& adj);

int main(){
  int n; cin >> n;
  vector<vector<int>> adj(n);
  for(int i=1;i<n;i++){
    int a; cin >> a;
    a--;
    adj.at(a).push_back(i);
  }
  if(df){
    for(int i=0;i<n;i++){
      printf("%d [ ",i);
      for(const int& v: adj.at(i)){
	printf("%d ",v);
      }
      cout << "]\n";
    }
  }
   int h=dfs(0,adj);
   cout << h;
}

int dfs(int v,vector<vector<int>> const& adj){
  vector<int> vec;
  for(const int& u: adj.at(v)){
    vec.push_back(dfs(u,adj));
  }
  sort(vec.begin(),vec.end(),greater<int>());
  if(df){
    printf("dfs %d:[ ",v);
    for(const int& k:vec){
      printf("%d ",k);
    }
    printf("]   ");
  }
  int MAX_vec=0, i=1;
  for(const int& k: vec){
    if(df)printf(" %d",k+i);
    if(MAX_vec<k+i)MAX_vec=k+i;
    i++;
  }
  if(df)printf("-> h:%d\n",MAX_vec);
  return MAX_vec;
}

/// confirm df==0 ///
