#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
#define pi 3.14159265358979323846
#define ill long long int
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  ill n, k, x, y, sum;
  cin >> n >> k >> x >> y;
  if(n <= k){
    cout << n * x << "\n";
    return 0;
  }
  n -= k;
  y = y * n;
  x = x * k;
  cout << x + y << "\n";
}
  