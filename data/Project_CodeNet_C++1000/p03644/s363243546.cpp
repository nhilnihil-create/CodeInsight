#include <bits/stdc++.h>
using namespace std;

int solve(int n) { 
    int cnt = 0;
    while (n%2==0) {
      n /= 2;
      cnt++;
    }
    return cnt;
}

int main() { 
    int n, check=0,out=1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      if (check != max(check, solve(i))) {
        out = i;
        check = max(check, solve(i));
      }
      else
        continue;
    }
    cout << out << endl;
    return 0;
}