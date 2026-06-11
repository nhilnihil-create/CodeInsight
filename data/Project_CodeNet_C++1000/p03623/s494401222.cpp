#include <bits/stdc++.h>
#include <vector>
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;
using namespace std;
int main(){
  int x,a,b;
  cin >> x >> a >> b;
  if(abs(x - a) > abs(x - b)){
    cout << "B" << endl;
  }else{
    cout << "A" << endl;
  }
  return 0;
}