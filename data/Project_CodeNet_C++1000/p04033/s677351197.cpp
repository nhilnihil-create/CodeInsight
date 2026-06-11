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
  ll int a, b, c;
  cin >> a >> b;
  if(a > 0 && b > 0){
    cout << "Positive\n";
    return 0;
  }
  if(a * b < 0){
    cout << "Zero\n";
    return 0;
  }
  c = b - a + 1;
  if(c % 2 == 0){
    cout << "Positive\n";
    return 0;
  }
  cout << "Negative\n";
}
  