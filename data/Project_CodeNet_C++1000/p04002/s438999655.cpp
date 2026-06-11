#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int H,W,N;
  cin >> H >> W >> N;

  int dx[9] = {-1,0,1,-1,0,1,-1,0,1};
  int dy[9] = {1,1,1,0,0,0,-1,-1,-1};

  // 入力
  vector<int> a(N),b(N);
  set< pair<int,int> > s; // 黒マス判定用
  set< pair<int,int> > used; // 調査済み判定用
  for(int i=0;i<N;i++){
    cin >> a[i] >> b[i];
    s.insert(make_pair(a[i],b[i]));
  }

  ll ans[10];
  for(int i=0;i<10;i++) ans[i] = 0;

  // 黒マスについて探索
  for(int i=0;i<N;i++){

    // 黒マス中心の3x3マスの調査 3x3にならないマス 調査済みマスはスルー
    for(int j=0;j<9;j++){
      int cx = b[i]+dx[j], cy = a[i]+dy[j];
      if(cx<2||W-1<cx||cy<2||H-1<cy) continue;
      if(used.count(make_pair(cy,cx)) == 1) continue;

      // 3x3マスの調査 黒マスのカウント
      int tmp=0;
      for(int k=0;k<9;k++){
        int nx = cx + dx[k], ny = cy + dy[k];
        if(s.count(make_pair(ny,nx)) == 1)tmp++; // 黒マスであればカウント
        if(k == 8){
          used.insert(make_pair(cy,cx)); // 調査済みマスに追加
          ans[tmp]++;
        }
      }
    }
  }

  ll sum = 0;
  for(int i=0;i<10;i++) sum += ans[i];
  printf("%lld\n",((ll)H-2) * ((ll)W-2) - sum );
  for(int i=1;i<10;i++){
    printf("%lld\n",ans[i]);
  }
  return 0;
}
