#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  vector<int> vec(3);
  for (int i = 0; i < vec.size(); i++){
    cin >> vec.at(i);
  }

  int five = 0;
  int seven = 0;

  for (int e : vec){
    if (e == 5) five += 1;
    if (e == 7) seven += 1;
  }

  cout << (five == 2 && seven == 1 ? "YES" : "NO") << endl;
}