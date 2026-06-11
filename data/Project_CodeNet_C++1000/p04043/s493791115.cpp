#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  vector<int> a;
  for(int i = 0; i <3; i++){
    int tmp;
    cin >> tmp;
    a.push_back(tmp);
  }
  sort(a.begin(), a.end());
  if((a[0] == a[1] && a[0] == 5) && (a[2] == 7)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}