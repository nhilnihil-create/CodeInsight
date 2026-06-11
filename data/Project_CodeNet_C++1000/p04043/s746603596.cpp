#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int input() {
  int x;
  cin >> x;
  return x;
}

vector<int> vecinput(int x) {
  vector<int> vec(x);
  for (int i = 0; i < x; i++)
    cin >> vec[i];
  return vec;
}
 
int main() {
    vector<int> ABC = vecinput(3);
    vector<int> tanka = {5,5,7};
    sort(ABC.begin(), ABC.end());
    if (ABC==tanka){
        cout << "YES" <<endl;
    }
    else{
        cout << "NO" <<endl;
    }
}