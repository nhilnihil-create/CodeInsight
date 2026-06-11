#include <iostream>
#include <cmath>

using namespace std;
int main(){
  long n;
  cin >> n;

  int min_f = 100;
  for(long i = 1L; i <= sqrt(n); i++) {
    if(n%i == 0) {
      long tmp_max = max(i, n/i);
      int tmp_f = 1;
      while(tmp_max != 0) {
        tmp_max = tmp_max/10;
        if(tmp_max != 0) {
          tmp_f++;
        }
      }
      min_f = min(min_f, tmp_f);
    }
  }

  cout << min_f << endl;
  return 0;
}
