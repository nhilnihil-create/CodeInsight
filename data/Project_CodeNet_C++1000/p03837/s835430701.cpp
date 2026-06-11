 #include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
using P = pair<int, int>;
const long long INF = 100000000;
//ダイクストラ法の練習

int main(){
  int N,M;
  cin >> N >> M;
  vector<vector<int>> edge(101, vector<int> (0));
  vector<vector<int>> L(101, vector<int> (101) );
  rep(i, M){
    int a, b,c;
    cin >>a>>b>>c;
    edge[a].push_back(b);
    edge[b].push_back(a);
    L[a][b] = c;
    L[b][a] = c;
  }
  
  vector<vector<int>> min_dist(101, vector<int> (101));
  
  //スタートがi
  for(int i = 1; i < N; i++){
    
    //int i = 1;//テスト
  
      //準備
      priority_queue<P, vector<P>, greater<P>> pq;//pair<仮の距離、頂点>仮の距離が小さい順に並ぶ
      vector<int> dist(N+1, INF);//スタートからの最短距離を更新し続ける
        
  
  
      //初期条件
      dist[0] = 0;//頂点0は使わない
      dist[i] = 0;//頂点iまでの距離は0
      pq.push(make_pair(dist[i], i));
            
      //jが確定するまで続ける
      while(!pq.empty()){
        P p = pq.top();//仮距離最小を取り出す
        pq.pop();//削除する
        int v = p.second;//頂点を取り出す
        //更新しない場合
        //if(dist[v] < p.first){
         // continue;
       // }
        //更新する場合,vから行けるすべての頂点に対して
        for(int u:edge[v]){
          if(dist[v]+L[v][u] < dist[u]){
            dist[u] = dist[v]+L[v][u];
          
            pq.push(make_pair(dist[u], u));
          }
        }
      }
    //記録する
    for(int j = i+1; j <= N; j++){
      min_dist[i][j] = dist[j];
      min_dist[j][i] = dist[j];
    }      
  }
  
  int counter = 0;
  for(int i = 1; i <= N; i++){
    for(int j: edge[i]){
      bool x = false;
      for(int s = 1; s <= N; s++){
        if(min_dist[s][i]+ L[i][j] == min_dist[s][j]){
          x = true;
        }
      }
      if(x){
        counter++;
      }
    }
  }
   cout << M-counter/2 << endl;

    
  
  //rep(i, N+1){
 //  rep(j, N+1){
    //cout << min_dist[i][j] << " ";  
   //}
   // cout << endl;
  //}
}



