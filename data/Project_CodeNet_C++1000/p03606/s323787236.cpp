#include <bits/stdc++.h>
using namespace std;
 
int main() {
 int N,l,r,a,b;
 cin >> N;
  for(int i;i<N;i++){
    cin >> l >> r;
    a= a+r-l;
  }
  cout << a+N << endl;
}
