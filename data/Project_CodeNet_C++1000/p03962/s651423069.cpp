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
  int a[3];
  rep(i, 0, 3){
    cin >> a[i];
  }
  if(a[0] == a[1]){
    if(a[0] == a[2]){
      cout << "1\n";
      return 0;
    }
    cout << "2\n";
    return 0;
  }
  if(a[0] != a[2]){
    if(a[1] != a[2]){
      cout << "3\n";
      return 0;
    }
  }
  
  cout << "2\n";
  return 0;
}