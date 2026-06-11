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
  ill a, b;
  cin >> a >> b;
  if(a == b){
    cout << "Draw\n";
    return 0;
  }
  if(a == 1){
    cout << "Alice\n";
    return 0;
  }
  if(b == 1){
    cout << "Bob\n";
    return 0;
  }
  if(a > b){
    cout << "Alice\n";
    return 0;
  }
  cout << "Bob\n";
  return 0;
}