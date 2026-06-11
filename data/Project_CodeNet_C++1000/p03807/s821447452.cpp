#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0;i < n; i++) cin >> a.at(i);

     int odd = 0 , even = 0;
     for (int i = 0;i < n; i++) {
         if (a.at(i) % 2 == 0) even++;
         else odd++;
     }

     //cout << "odd" << odd << "even" << even << endl;

     bool can = false;

     if (n % 2 != 0) {
         if (odd % 2 == 0 && even % 2 != 0) can = true;
     }
     else {
         if (odd % 2 != 0 && even % 2 != 0);
         else can = true;
     }
     if(can) cout << "YES" << endl;
     else cout << "NO" << endl;
     return 0;
}