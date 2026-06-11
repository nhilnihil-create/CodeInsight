#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  int result;
  int k;
  cin >> k;
  result = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x<=k-x)
        {
            result = result +x*2;
        }
        else if (k-x < x)
        {
            result = result + (k-x)*2;
        }
    }
    cout << result << endl;
}