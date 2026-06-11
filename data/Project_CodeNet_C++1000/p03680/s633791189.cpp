#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int N;
  cin >> N;
  vector <int> vec(N);//a_i
  rep(i,N) cin >> vec.at(i);

  int count = 0;
  int a = 0;
  while (true){
    count++;
    a = vec.at(a) - 1;
    if (a == 1) break;
    if (count > N){
      count = -1;
      break;
    }
  }
  cout << count << endl;

}
