#include <bits/stdc++.h>
using namespace std;

int main(){
  string a, b;
  cin >> a >> b;
  int s = a.size();
  int t = b.size();

  if (s - t == 0){
  for (int i = 0; i < s; i++){
     cout << a[i] << b[i];
  }
}
else{
  for (int i = 0; i < s-1; i++){
     cout << a[i] << b[i];
  }
     cout << a[s-1];
}
}