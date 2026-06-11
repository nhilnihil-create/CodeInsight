#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int sx,sy,tx,ty;
  cin >> sx >> sy >> tx >> ty;

  const int w = 2100;
  const int h = 2100;

  //訪問済みの座標を記録するvector
  vector<vector<int>> visited(h,vector<int>(w,0));

  //どの方向から移動してきたかを記録するvector
  vector<vector<char>> direction(h,vector<char>(w));

  //座標値を配列の添え字に変換する関数
  auto to_idx = [&](int c){
    return c + 1005;
  };

  //与えられた2点の座標を配列の添え字に変換
  const int sx_ = to_idx(sx);
  const int sy_ = to_idx(sy);
  const int tx_ = to_idx(tx);
  const int ty_ = to_idx(ty);
  
  string ans;

  //4回の移動を行う
  rep(I,4){
    //出発地点の座標と対応する配列の添え字
    int nx,ny;

    //出発地点の座標と対応する配列の添え字
    int gx,gy;

    //出発地点と目標地点をセット
    if(I%2==0){
      nx = sx_;
      ny = sy_;
      gx = tx_;
      gy = ty_;
    }
    else{
      nx = tx_;
      ny = ty_;
      gx = sx_;
      gy = sy_;
    }

    //目標地点を未訪問にしておく
    visited[gy][gx] = 0;

    /*BFS（多分）する*/
    queue<P> q;
    const int dx[4] = { 0, 1,-1, 0};
    const int dy[4] = { 1, 0, 0,-1};
    const char di[4] = {'U','R','L','D'};

    //訪問済みの座標を記録するvector（最短経路上ではない座標も記録）
    vector<vector<int>> tmp_visited(h,vector<int>(w,0));

    //出発地点をキューに追加
    q.push(make_pair(nx,ny));

    while(!q.empty()){
      //目標地点に到達したかのフラグ
      bool reached = false;

      P p = q.front();
      q.pop();

      int X = p.first;
      int Y = p.second;

      rep(i,4){
        int to_x = X + dx[i];
        int to_y = Y + dy[i];

        //行先の座標が範囲外ならば
        if(0>to_x||to_x>=w) continue;
        if(0>to_y||to_y>=h) continue;

        //行先の座標が訪問済みならば
        if(visited[to_y][to_x]==1||tmp_visited[to_y][to_x]==1) continue;

        //訪問済みにしておく
        tmp_visited[to_y][to_x] = 1;

        //移動してきた方向を記す
        direction[to_y][to_x] = di[i];

        //目標地点に到達したら
        if(to_x==gx&&to_y==gy) reached = true;

        //キューに追加
        q.push(make_pair(to_x,to_y));
      }

      //目標地点に到着したときそれまでの経路を記録する
      if(reached){
        string tmp_ans;

        //出発地点に到達したかのフラグにする
        reached = false;

        int to_x = gx;
        int to_y = gy;

        while(!reached){
          //経路を記録
          tmp_ans = direction[to_y][to_x] + tmp_ans;

          //訪問済みにしておく
          visited[to_y][to_x] = 1;

          //経路を戻る
          if(direction[to_y][to_x]=='U') to_y--;
          else if(direction[to_y][to_x]=='D') to_y++;
          else if(direction[to_y][to_x]=='L') to_x++;
          else if(direction[to_y][to_x]=='R') to_x--;

          //出発地点に到着したら
          if(to_x==nx&&to_y==ny) reached = true;
        }

        ans += tmp_ans;

        break;
      }

    }

  }

  cout << ans << endl;

  return 0;
}