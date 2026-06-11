#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W,N;
  cin >> H >> W >> N;

  bool is_satisfied= false;
  for(int h=0; h<=H; h++){
    for(int w=0; w<=W; w++){
      if(h*(W-w)+ (H-h)*w == N){
        is_satisfied= true;
        break;
      }
    }
  }

  string ans= is_satisfied ? "Yes"
                           : "No";
  cout << ans << endl;
}