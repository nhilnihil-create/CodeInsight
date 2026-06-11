#include"bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long INT;
double PI = 3.14159265;

const long long INF = 1LL << 60;


int main() {
    int a[300010] = {},n;
    INT sum=0;

    cin >> n;

    rep(i, n * 3)cin >> a[i];

    sort(a, a + n * 3,greater<int>());

    rep(i, n)sum += a[i * 2 + 1];

    cout << sum << endl;

  return 0;
}