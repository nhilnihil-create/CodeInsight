#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i,n) for(int i = 0; i , (n); ++i)
using ll = long long;
using namespace std;
int sum(int n) {
    if (n == 0) {
        return 0;
    }

    int s = sum(n - 1);
    return s + n;
}
int main() {
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D;
    E = max(A, C);
    F = min(B, D);
  if(F-E>0){
    cout << F - E;
  }
  else{
 	cout<<0;
  }
}
