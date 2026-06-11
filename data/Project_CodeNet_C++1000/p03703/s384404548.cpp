#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MAX 300003
#define MOD 998244353
#define INF 1000000000000000

int solve(int a,int b,int i,int left,int right,vector<int> &tree){
  if(b<=left||right<=a){
    return 0;
  }
  if(a<=left&&right<=b){
    return tree.at(i);
  }
  return solve(a,b,2*i+1,left,(left+right)/2,tree)+solve(a,b,2*i+2,(left+right)/2,right,tree);
}

void plus_tree(vector<int> &tree,int i){
  tree.at(i)++;
  while(i>0){
    i=(i-1)/2;
    tree.at(i)=tree.at(2*i+1)+tree.at(2*i+2);
  }
}

int main(){
  ll N,K;
  cin>>N>>K;
  vector<ll> a(N);
  for(int i=0;i<N;i++){
    cin>>a.at(i);
  }

  vector<ll> sum(N+1,0);
  for(int i=0;i<N;i++){
    sum.at(i+1)=sum.at(i)+a.at(i);
  }

  vector<ll> B(N+1);
  for(ll i=0;i<N+1;i++){
    B.at(i)=sum.at(i)-i*K;
  }
  vector<ll> C=B;
  sort(C.begin(),C.end());
  map<ll,int> m;
  int x=0;
  for(int i=0;i<N+1;i++){
    if(i==0){
      m[C.at(i)]=x;
    }else{
      if(C.at(i)!=C.at(i-1)){
        x++;
      }
      m[C.at(i)]=x;
    }
  }

  vector<int> coor(N+1);
  for(int i=0;i<N+1;i++){
    coor.at(i)=m[B.at(i)];
  }

  int n=1;
  while(n<N+1){
    n<<=1;
  }

  vector<int> tree(2*n-1,0);
  ll ans=0;
  plus_tree(tree,n-1+coor.at(0));
  for(int i=0;i<N;i++){
    ans+=(ll)solve(0,coor.at(i+1)+1,0,0,n,tree);
    plus_tree(tree,n-1+coor.at(i+1));
  }
  cout<<ans<<endl;
}
