#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;            //

int main(void)
{
    int a, b, c;
    cin >> a >> b >> c;
  
    int sum = min({a + b, b + c, c + a});
    cout << sum << endl;
    return (0);
}