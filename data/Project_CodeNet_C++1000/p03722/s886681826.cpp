#include <bits/stdc++.h>
#include <stdio.h>
#include <ios>     
#include <iomanip> 

using namespace std;
#define inputInt(a) int a; cin >> a; 
#define inputInt2(a,b) int a; int b; cin >> a >> b; 
#define inputInt3(a,b,c) int a; int b; int c; cin >> a >> b >> c;
#define inputLong(a) long a;cin >> a; 
#define inputIntArray(a,N) int a[N];for(int i=0;i<N;i++){cin >> a[i];}
#define inputLongArray(a,N) long a[N];for(int i=0;i<N;i++){cin >> a[i];}
#define inputIntArray2(a,b,N) int a[N]; int b[N]; for(int i=0;i<N;i++){cin >> a[i] >> b[i];}
#define output(answer) cout << answer << endl;
#define fN(i,N)    for(int i=0; i<N; i++)
#define fSE(i,s,e) for(int i=s; i<=e; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const long long int INF = 1e18;

int main(){
  //この問題は多重辺無し。
  //input
  inputInt2(N,M);
  
  vector<vector<pair<int,long long int>>> graph(N); //graph[from][i番目の辺].<to,cost>
  for(int i=0; i<M; i++){
    int from, to;
    long long int cost;
    cin >> from >> to >> cost;
    from --; to --; cost *= -1;//最長経路問題を最短経路問題に帰着させるため。
    graph[from].pb(mp(to,cost));
    //graph[to].pb(mp(from,cost));
  }
  
  //main
  //ベルマンフォード法
  vector<long long int> d(N,INF);
  d[0] = 0;//頂点1までの距離を0に。
  bool NegativeLoop = false;
  
  for(int it=0; it<N*2+1; it++){//念のため頂点数の2倍ループを回す。
    for(int v=0; v<N; v++){//for auto文との組み合わせで1セット。
      if(d[v]>INF/2) continue; //無駄を省く&オーバーフロー対策。
      for(auto edge:graph[v]){//edgeはpair型
        if(d[edge.first] > d[v] + edge.second){
          d[edge.first] = d[v] + edge.second;
          if(edge.first == N-1 && it == N*2){
            NegativeLoop = true; 
          }
        }
      }
    }
  }
  
  //確認用
  /*for(int i=0; i<N; i++){
    cout << d[i] << endl;
  }*/
  
  // output
  if(NegativeLoop){
    cout << "inf" << endl;
  }else{
    cout << -d[N-1] << endl; 
  }
    
  return 0;
}