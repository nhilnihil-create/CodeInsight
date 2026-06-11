#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, o = 0;
  long long a;
  cin >> n;
  while(n--){
    cin >> a;
    if(a%2 != 0) ++o;
  }
  cout << (o%2 == 0 ? "YES" : "NO") << endl;
}