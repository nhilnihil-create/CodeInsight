#include <iostream>
#include <map>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;

int main(){
  int N;
  cin >> N;
  int A[N];
  rep(i, N)
    cin >> A[i];
  //ここまで入力

  //縦と横の辺
  long long edge1, edge2;

  //mappingの作成
  map<int, int> mapp;
  rep(i, N)
    mapp[A[i]]++;
    
  pair<int, int> max = make_pair(0, 0);
  //二本以上ある辺のうち，最大のものを探す
  for(auto m : mapp)
    if(m.first > max.first && m.second >= 2)
      max = m;
  mapp[max.first] = 0;
  edge1 = max.first;

  //最大長の辺で正方形が作れるとき
  if(max.second >= 4){
    cout << edge1 * edge1 << endl;
    return 0;
  }
    
  //二本以上ある辺のうち，二番目に大きいものを探す
  max = make_pair(0, 0);
  for(auto m : mapp)
    if(m.first > max.first && m.second >= 2)
      max = m;
  edge2 = max.first;

  //面積
  cout << edge1 * edge2 << endl;

  return 0;
}
