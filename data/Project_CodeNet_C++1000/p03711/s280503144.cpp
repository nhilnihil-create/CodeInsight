#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep2(i, a, b) for(int i = (a); i < (b); i++)
typedef long long ll;

int main() {
   int x, y;
   cin >> x >> y;

   int a[] = {0, 2, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0};

   if (a[x-1] == a[y-1]) {
       cout << "Yes" << endl;
   } else {
       cout << "No" << endl;
   }
}