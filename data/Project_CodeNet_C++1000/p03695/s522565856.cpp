#include <iostream>
#define rep(i, n) for(int i =0; i<n; i++)

using namespace std;

int main(void){
  int N;
  cin >> N;
  int a[N];
  rep(i, N)
    cin >> a[i];
  //入力終了

  //rating3200以上の人のことを「自由人」と呼ぶことにする
  
  //各色の人数を記録
  //colors[8]には自由人の人数を記録
  int colors[9] = {0};

  rep(i, N){
    if(1<=a[i] && a[i]<=399)
      colors[0]++;
    else if(400<=a[i] && a[i]<=799)
      colors[1]++;
    else if(800<=a[i] && a[i]<=1199)
      colors[2]++;
    else if(1200<=a[i] && a[i]<=1599)
      colors[3]++;
    else if(1600<=a[i] && a[i]<=1999)
      colors[4]++;
    else if(2000<=a[i] && a[i]<=2399)
      colors[5]++;
    else if(2400<=a[i] && a[i]<=2799)
      colors[6]++;
    else if(2800<=a[i] && a[i]<=3199)
      colors[7]++;
    else
      colors[8]++;
  }

  int ans = 0;
  rep(i, 8){
    //各色の人が一人でもいればカウント
    if(colors[i]>0)
      ans++;
  }

  //最小の時の解答
  //自由人しかいない時
  if(ans == 0)
    cout << 1 << " ";
  //自由人は既にある色のみを選ぶ
  else
    cout << ans << " ";

  //最大の時の解答
  //自由人はできるだけ多くの色が出るように選ぶ
  cout << ans+colors[8] << endl;
  
  return 0;
}
