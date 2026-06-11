#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int e = a * b, f = c * d;
  if(e < f){
    cout << f << "\n";
  }
  else{
    cout << e << "\n";
  }
}
