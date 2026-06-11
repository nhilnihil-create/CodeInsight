#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n];
  int odd = 0, mul4 = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    if(a[i] % 4 == 0) {
      mul4++;
    } else if (a[i] % 2 != 0) {
      odd++;
    }
  }

  if(odd -1 < mul4) {
    cout << "Yes" << endl;
  } else if ((odd -1 == mul4) && (odd + mul4 == n)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
