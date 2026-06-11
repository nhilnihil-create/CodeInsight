#include <iostream>
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(void){
  int N, M;
  cin >> N >> M;
  int a[N], b[N];
  rep(i, N)
    cin >> a[i] >> b[i];
  int c[M], d[M];
  rep(i, M)
    cin >> c[i] >> d[i];
  //入力終了

  rep(i, N){
    //距離の最小値と，その地点
    int min = 1000000000, point;
    rep(j, M){
      //最小値更新
      if( (abs(a[i]-c[j]) + abs(b[i]-d[j])) < min){
	min = abs(a[i]-c[j]) + abs(b[i]-d[j]);
	point = j+1;
      }
    }
    //学生iの解答
    cout << point << endl;
  }
    
  return 0;
}
