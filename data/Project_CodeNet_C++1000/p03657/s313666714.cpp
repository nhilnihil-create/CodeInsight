#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)


int main() {
    int A,B;cin >> A >> B;
    if (A%3 == B%3){
      if (A%3 == 0){
        cout << "Possible" << endl;
      }else{
        cout << "Impossible" << endl;
      }
    }else{
      cout << "Possible" << endl;
    }

  }       