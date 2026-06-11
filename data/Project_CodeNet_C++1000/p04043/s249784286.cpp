#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int cnt5 = 0;
    int cnt7 = 0;
    if (a == 5) {
        cnt5++;
    }
    if (b == 5) {
        cnt5++;
    }
    if (c == 5) {
        cnt5++;
    }
    if (a == 7) {
        cnt7++;
    }
    if (b == 7) {
        cnt7++;
    }
    if (c == 7) {
        cnt7++;
    }
    if (cnt5 == 2 && cnt7 == 1) cout << "YES";
    else cout << "NO";
  return 0;
}