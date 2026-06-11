#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
//const int MOD=998244353;
const int INF=1e9;
const long long LINF=1e18;
//template
template <typename T>
void fin(T a){
  cout<<a<<endl;
  exit(0);
}
std::vector<int> edge[100005];
int f(int pa,int idx){
  int res=0;
  for(int p:edge[idx]){
    if(p==pa)continue;
    res^=f(idx,p);
  }
  return res+1;
}
//main
signed main(){
  int N;cin>>N;
  for(int i=1;i<N;i++){
    int a,b;cin>>a>>b;a--;b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  if(f(-1,0)==1)fin("Bob");
  fin("Alice");
}


/*
解説AC
根付き木にするとNimっぽいってところまでは考えたけど部分根付き木のアイデアがなかったね
根付き木->部分根付き木までをセットで知識に入れとく
証明としては普通のNimとそんなにかわらないのかな、各それに対して同じように対応されたら無理なので
アイデアさえ思いつければいいのかねぇ
実装上手く描けて嬉しい
*/
