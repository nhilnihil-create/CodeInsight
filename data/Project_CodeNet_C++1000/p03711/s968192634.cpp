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
  int x, y, xx = 0, yy = 0;
  cin >> x >> y;
  int a[4];
  a[0] = 4;
  a[1] = 6;
  a[2] = 9;
  a[3] = 11;
  if(x == y){
    cout << "Yes\n";
    return 0;
  }
  if(x == 2){
    cout << "No\n";
    return 0;
  }
  if(y == 2){
    cout << "No\n";
    return 0;
  }
  rep(i, 0, 4){
    if(x == a[i]){
      xx++;
      break;
    }
  }
  rep(i, 0, 4){
    if(y == a[i]){
      yy++;
      break;
    }
  }
  
  if(xx == yy){
    cout << "Yes\n";
    return 0;
  }
  cout << "No";
}
