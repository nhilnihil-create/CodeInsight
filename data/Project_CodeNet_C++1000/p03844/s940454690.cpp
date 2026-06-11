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
  int a, b;
  char c;
  cin >> a >> c >> b;
  if(c == '+'){
    cout << a + b << "\n";
    return 0;
  }
  if(c == '-'){
    cout << a - b << "\n";
    return 0;
  }
  cout << a * b << "\n";
}