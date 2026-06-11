#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int64_t a=1;
  for(int i=1;i<=n;i++)
    a=a*i%1000000007;
  cout << a << endl;
}