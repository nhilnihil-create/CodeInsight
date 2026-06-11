#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  int a[12]={3,1,3,2,3,2,3,3,2,3,2,3};
  int i,j; cin >> i >> j;
  if(a[i-1] == a[j-1]){
    cout << "Yes";
  }
  else{
    cout << "No";
  }
}