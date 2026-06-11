#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int N; cin >> N;
    int c2 = 0, c4 = 0;
    for(int i = 0; i < N; i++){
        int a; cin >> a;
        if(a % 4 == 0) c4++;
        else if(a % 2 == 0) c2++;
    }
    int c1 = N - c2 - c4;
    if(c2 == 0){
      if(c1 <= c4 + 1) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  if(c2 != 0){
    if(c1 <= c4) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}