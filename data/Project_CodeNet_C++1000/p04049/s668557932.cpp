#include <bits/stdc++.h>
using namespace std;
/*
直径がもともとK以下なら0でよくて、Kより大きいならちょうどKにしたいはず
根付き木で考えた場合、全部深さがK/2以下くらいならよさそう？
でも実際は、一つの葉の深さだけ大きくて残りの葉の深さを減らすだったり、そもそも根自体を使わない選択肢もある
出来上がるのも木で、距離がKになる葉の組みが存在する
それらを結んで、そこからのそれはそいつらを越さないようにするので一意に決まる
つまり？距離がKの2点を選ぶのが2e6通り
そこから進んでいくのが2e3通り？
距離がKの点はKが2だったりするとうにで沢山
距離がKの点でも一回見たやつはなくすとかで案外？
やってみよう！
*/
int d[2005];
struct e{int a,b,d;};
template<typename T>
void chmax(T &a,T b){
  if(a<b)a=b;
}

signed main(){
  int n,k;cin>>n>>k;
  vector<int> edge[n];
  for(int i=0;i<n-1;i++){
    int a,b;cin>>a>>b;a--;b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  int ans=0;
  if(k&1){
    queue<e> que;
    for(int a=0;a<n;a++){
      for(int b:edge[a]){
        que.push({a,b,0});
        que.push({b,a,0});
        int res=0;
        while(que.size()){
          e p=que.front();que.pop();
          int u=p.a,pre=p.b,d=p.d;
          res++;if(d==k/2)continue;
          for(int q:edge[u]){
            if(q==pre)continue;
            que.push({q,u,d+1});
          }
        }
        chmax(ans,res);
      }
    }
    cout<<n-ans<<endl;
  }
  else{
    queue<e> que;
    for(int a=0;a<n;a++){
      que.push({a,-1,0});
      int res=0;
      while(que.size()){
        e p=que.front();que.pop();
        int u=p.a,pre=p.b,d=p.d;
        res++;if(d==k/2)continue;
        for(int q:edge[u]){
          if(q==pre)continue;
          que.push({q,u,d+1});
        }
      }
      chmax(ans,res);
    }
    cout<<n-ans<<endl;
  }
}

/*
解説AC
これは解けてよかったんじゃないか？なんか根付き木がダメなのはそうで
両端全探索も多分うまく実装して差がKのペアを全部ちょうど一回ずつだけ試せれば通せたとは思うけど流石にやばすぎ
中心って概念知らなかったけど両端全探索でも結局やろうとしていたこと自体はほぼ一緒なんだよな
悲しいね
とりあえず中心って概念は覚えよう　木だけじゃなくて距離の上限に対して強そう？結局木構造にしか使えない気もするけど
*/
