#include <bits/stdc++.h>
using namespace std;

bool selected[101];

int main(){
  int n; cin >> n;
  vector<int> score(n);
  for(int i = 0; i < n; ++i) {
    int tmp; cin >> tmp;
	score.push_back(tmp);
  }
  sort(score.rbegin(), score.rend());
  int ans = 0;
  for(int i = 0; i < n; ++i)selected[i] = false;
  for(int i = 0; i < 101; ++i){
  	for(int j = 0; j < n; ++j){
      if(selected[j] == false && (ans + score[j]) % 10 != 0){
        ans += score[j];
        selected[j] = true;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0; 
}
