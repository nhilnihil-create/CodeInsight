#include <iostream>

#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(){
  int N;
  string s, t;
  cin >> N >> s >> t;
  //入力終了

  //文字列tの，t_start番目からsに連結させる
  int t_start;

  //t_startの最大値(開始場所をできるだけ右にずらす)
  int max_start = 0;
  rep(i, N){
    t_start = 0;
    int j = i;
    //sのi文字目以降と，tの0文字目以降を見ていく
    //一致する限り右にずらせる
    while(s[j++] == t[t_start] && j<=N)
      t_start++;
    //tの開始位置を最大化
    if(t_start > max_start)
      max_start = t_start;
  }

  //必ずsは出力される
  cout << s.size() + (t.size()-max_start) << endl;
  
  //実際の文字列
  /*cout << s ;
  if(max_start < N){
    rep(i, t.size()-max_start)
      cout << t[i+max_start];
    cout << endl;
    return 0;
  }
  cout << endl;*/
  
  return 0;
}
