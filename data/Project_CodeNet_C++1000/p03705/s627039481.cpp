#include <iostream>
#define ll long long
using namespace std;

int main() {
      ll N, A, B;
      cin >> N >> A >> B;

      ll min = (N-1) * A + B;
      ll max = A + (N-1) * B;

      if(N==1 && A==B) cout << 1 << endl;
      else if(max >= min) cout << max - min + 1 << endl;
      else cout << 0 << endl;
}