#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
     int N;
    int a[1100000];
    cin >> N ;
    long int res = 0;
    for(int i=0;i<N*3;++i) cin >> a[i];
    sort(a,a+(N*3),greater<int>());
    for(int i = 0;i < N * 2;++i){
      if((i + 1) % 2 == 0) {
          res += a[i];
      }
    }
    cout << res << endl;
}