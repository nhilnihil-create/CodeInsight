#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin >> a>>b;
  vector<char>vec(a*b);
  for (int i=0;i<(a*b);i++){
    cin >> vec[i];
  }
  for (int j=0;j<(b+2);j++){
    cout<< '#';
  }
  cout << endl;
  for(int m=0;m<a;m++){
    cout <<'#';
    for(int n=0;n<b;n++){
      cout << vec.at(n+m*b) ;
    }
    cout <<'#';
    cout << endl;
  }
  for(int i=0;i<b+2;i++){
    cout <<'#';
  }
  cout << endl;
}
