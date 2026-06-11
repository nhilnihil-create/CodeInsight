// Example program
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
      int n = 0;
      cin >> n;
      ll l = 0, r = 0;
      ll res = 0;
      for(int i = 0; i < n; ++i){
            cin >> l >> r;
            r-=l;
            res+=r;
            ++res;
        } 
      cout << res << endl;

}
