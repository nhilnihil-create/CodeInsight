#include<bits/stdc++.h>
using namespace std;

int sum(int ame) {
  if(ame==0) {
    return 0;
  }
  int s=sum(ame-1);
    return ame+s;
}
int main() {
  int children;
  cin >> children;
  cout << sum(children) << endl;
}