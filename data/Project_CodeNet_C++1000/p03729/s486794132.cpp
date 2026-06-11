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
  string a, b, c;
  cin >> a>> b >> c;
  int aa = a.size();
  int bb = b.size();
  if(a[aa - 1] == b[0]){
    if(b[bb - 1] == c[0]){
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
}