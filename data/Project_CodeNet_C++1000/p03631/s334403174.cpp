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
  char b;
  rep(i, 0, 3){
    char c;
    cin >> c;
    if(i == 0){
      b = c;
    }
    if(i == 2){
      if(b == c){
        cout << "Yes\n";
        return 0;
      }
    }
  }
  cout << "No\n";
}