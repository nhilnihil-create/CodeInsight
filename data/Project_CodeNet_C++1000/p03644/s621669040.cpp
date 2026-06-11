#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int k=1;
  while(k<=n)
    k*=2;
  cout << k/2 << endl;
}