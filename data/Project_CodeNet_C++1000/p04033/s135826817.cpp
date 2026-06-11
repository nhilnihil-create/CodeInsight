#include <iostream>
using namespace std;

int main() {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      int a,b;
      cin >> a >> b;

      if(a<=0 && b>=0) cout << "Zero";
      else if(a>0 && b>0) cout << "Positive";
      else if(a<0 && b<0) {
            if((b-a-1)%2 == 0) cout << "Positive"; // b-a to make positive
            else cout << "Negative";
      }
}