#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int N;
  cin >> N;

  /*
  vector <int> times(N + 1);
  for (int i = 1; i <= N; i++){
    int cnt = 0;
    while (i > 0){
      if (i % 2 == 0){
        i / 2;
        cnt ++;
      }else{
        return 0;
      }
    }
    times[i] = cnt;
  }

  vector <int>::iterator iter = max_element(all(times));
  size_t index = distance(times.begin(), iter);
  cout << index << endl;
  */

  int x = 1;
  while (x <= N) x <<= 1; //2をかける
  x /= 2;
  cout << x << endl;

}
