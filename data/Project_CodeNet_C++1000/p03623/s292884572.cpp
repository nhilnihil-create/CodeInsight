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
  ill a, b, x;
  cin >> x >> a >> b;
  a -= x;
  b -= x;
  if(b < 0){
    b = b * (-1);
  }
  if(a < 0){
    a = a * (-1);
  }
  
  if(a < b){
    cout << "A\n";
    return 0;
  }
  cout << "B\n";
}