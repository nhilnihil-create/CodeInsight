#include <iostream>
#define ll long long


 using namespace std;
 const int N = 110;
 int main() {
      int p, a, b;
      cin >> p >> a >> b;
      if(abs(p-a) < abs(p-b)) printf("A\n");
     else printf("B\n");
     return 0;
 }