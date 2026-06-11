#include <bits/stdc++.h>
using namespace std;
#define rep(i, seisu) for(int i = 0; i < (int)(seisu); i++)
typedef long long ll;


int main(){
  int n;
  cin >> n;
  vector<int> score;
  int ans = 0;
  int ten = 0;
  rep(i, n) {
    int x;
    cin >> x;
    score.push_back(x);
    ans += score[i];
    if(score[i] %10 == 0) ten++;
  }

  sort(score.begin(), score.end());

  
  int count = 0;
  int f = 0;
  if (ten == n){
    f = 1;
    ans = 0;
  
  }
  
  else{
  while(f == 0 && count < n){
    if(ans % 10 != 0){
      f = 1;
    }
    else{
      if (score[count]%10 != 0){
      ans -= score[count];
      count++;
      }
      else{
      count++ ;
    }
    }
  }
}

  cout << ans << endl;
}
