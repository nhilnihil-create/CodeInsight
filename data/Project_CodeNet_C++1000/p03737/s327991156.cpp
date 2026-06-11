#include <iostream>

using namespace std;

int main (void) {
   string a, b, c;
   cin >> a >> b >> c;
   
   int d = 'A' - 'a';
   
   string ans = "";

   ans += (a[0] + d);
   ans += (b[0] + d);
   ans += (c[0] + d);

   cout << ans << endl;


    return 0;
}