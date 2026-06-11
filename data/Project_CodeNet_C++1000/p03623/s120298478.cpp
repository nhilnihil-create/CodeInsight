      #include <iostream>
      #include <string>
      #include <vector>
      #include <algorithm>
      #include <utility>
      using namespace std;
      typedef long long ll;
      #define rep(i, n) for (int i=0;i < (int)(n);i++)

      int main(){
         int a,b,c;
         string s;
         cin >> a >> b >> c;
         if (abs(a-b) < abs(a-c)) cout << 'A' << endl;
         else cout << 'B' << endl;
         
         return 0;
         
      }

