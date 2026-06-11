#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int x;
  for(int i = 0; i<N; i++){
  int a, b;
  cin>>a>>b;
  x=x+(b-a)+1;
  }
  
  cout<<x<<endl;
}
