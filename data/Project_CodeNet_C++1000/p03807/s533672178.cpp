#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> a(N);

  for(int i = 0; i < N; i++){
    cin >> a.at(i);
  }

  int odd = 0;

  for(int i = 0; i < N; i++){
    if(a.at(i) % 2 == 1){
      odd++;
    }
  }

  if (odd % 2 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;

  // if(odd % 2 == 1){
  //   cout << "No" << endl;
  // }else{
  //   cout << "Yes" << endl;
  // }
}
