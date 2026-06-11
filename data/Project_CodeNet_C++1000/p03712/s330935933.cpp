#include<bits/stdc++.h>
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  vector<string> s(a);
  int i;
  for(i = 0;i < a;i++){
    cin >> s.at(i);
  }
  for(i = 0;i<=(b+1);i++){
    cout << '#';
  }
  cout << endl;
  for(i = 0;i<a;i++){
    cout << '#' << s.at(i) << '#' << endl;
  }
  for(i = 0;i<=(b+1);i++){
    cout << '#';
  }
}
