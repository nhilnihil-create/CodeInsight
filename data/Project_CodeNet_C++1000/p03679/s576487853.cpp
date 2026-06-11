#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
#define pi 3.14159265358979323846
#define ll long long
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  int x, a, b;
  cin >> x >> a >> b;
  if(a >= b){
    cout << "delicious\n";
    return 0;
  }
  b -= a;
  if(b <= x){
    cout << "safe\n";
    return 0;
  }
  cout << "dangerous\n";
}
           