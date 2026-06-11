#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

#define int long long

int ans, K, X;

int dfs(vector<vector<int>> & tree, int depth, int now, int per){
  int maximum = depth;

  for(int next : tree[now]){
    maximum = max(maximum, dfs(tree, depth+1, next, now));
    // cout<<now<<" -> "<<next<<endl;
  }
  // cout<<endl;
  //cout<<"K = "<<K<<" per "<<per<<endl;
  //cout<<"now "<<now<<" depth "<<depth<<" maximum "<<maximum<<" <> "<<maximum-depth<<" ans "<<ans<<endl;

  if(now == 0){

  } else if(per == 0){
    if(maximum - depth >= K){
      ans++;
      maximum = depth-1;
    }
  }else{
    if(maximum - depth >= K-1){
      ans++;
      maximum = depth-1;
    }
  }

  //  cout<<"now "<<now<<" depth "<<depth<<" maximum "<<maximum<<" <> "<<maximum-depth<<" ans "<<ans<<endl;

  return maximum;
}

signed main(){

  int N;
  vector<int> a;
  vector<vector<int>> tree;

  cin>>N>>K;

  a.resize(N);
  tree.resize(N);

  for(int i = 0; i < N; i++){
    cin>>a[i];

    a[i]--;

    if(!i) {
      if(a[i] != 0) ans++;
      continue;
    }

    tree[a[i]].push_back(i);
    //tree[i].push_back(a[i]);

  }

  dfs(tree, 0, 0, -1);

  cout<<ans<<endl;

  return 0;
}
