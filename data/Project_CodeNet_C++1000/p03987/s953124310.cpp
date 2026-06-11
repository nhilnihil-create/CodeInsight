#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MAX 500009
#define MOD 1000000007
#define INF 1000000000000000000

vector<pair<int,int>> tree;
int n=1;

void update(int i){
  int x=n-1+i;
  tree.at(x).first=i;
  tree.at(x).second=i;
  while(x>0){
    x=(x-1)/2;
    tree.at(x).first=min(tree.at(2*x+1).first,tree.at(2*x+2).first);
    tree.at(x).second=max(tree.at(2*x+1).second,tree.at(2*x+2).second);
  }
}

pair<int,int> solve(int a,int b,int i,int left,int right){
  if(b<=left||right<=a){
    return make_pair(n,-1);
  }
  if(a<=left&&right<=b){
    return tree.at(i);
  }
  pair<int,int> p1,p2;
  p1=solve(a,b,2*i+1,left,(left+right)/2);
  p2=solve(a,b,2*i+2,(left+right)/2,right);
  return make_pair(min(p1.first,p2.first),max(p1.second,p2.second));
}

int main(){
  int N;
  cin>>N;
  vector<pair<int,int>> a(N);
  for(int i=0;i<N;i++){
    cin>>a.at(i).first;
    a.at(i).second=i;
  }
  sort(a.begin(),a.end());
  while(n<N){
    n<<=1;
  }

  ll ans=0;
  tree.resize(2*n-1,make_pair(N,-1));
  for(int i=0;i<N;i++){
    int left=solve(0,a.at(i).second,0,0,n).second;
    int right=solve(a.at(i).second,N,0,0,n).first;
    ans+=(ll)a.at(i).first*((ll)a.at(i).second-(ll)left)*((ll)right-(ll)a.at(i).second);
    update(a.at(i).second);
  }

  cout<<ans<<endl;
}
