#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int sum = 0;
  for (int i; i<n; i++){
    int a;
    cin >> a;
    sum +=a;
  }
  cout << (sum%2==0 ? "YES":"NO") << endl;
}