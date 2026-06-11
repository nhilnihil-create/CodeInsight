#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define INF INT_MAX;
typedef long long ll;
using namespace std;

int N;
int64_t cont=0;


ll dfs(bool odd,int64_t sum,int i,vector<int64_t> &a){

  ll ans;
  if(i==N){
    ans = cont;
    cont =0;
    return ans;
  }

  if(odd){
    if(a[i]+sum<=0){
      cont += abs(1-sum-a[i]);
      sum = 1;
    }else{
      sum+=a[i];
    }
    //cout << i << endl;
    ans = dfs(false,sum,i+1,a);
  }else{
    if(a[i]+sum>=0){
      cont += abs(-1-sum-a[i]);
      sum = -1;
    }else{
      sum+=a[i];
    }
    //cout << i << endl;
    ans=dfs(true,sum,i+1,a);
  }

  return ans;
}

int main(){
  ll ans;
  cin >> N;
  vector<int64_t> a(N);
  for(int i=0;i<N;i++){
    cin >> a.at(i);
  }
  ans = min(dfs(true,0,0,a),dfs(false,0,0,a));
  cout << ans << endl;
}