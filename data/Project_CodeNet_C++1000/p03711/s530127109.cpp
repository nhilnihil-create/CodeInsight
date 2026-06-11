#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a = {1, 3, 5, 7, 8, 10, 12};
vector<int> b = {4, 6, 9, 11};
vector<int> c = {2};

int main(){
  int x, y;
  cin >> x >> y;
  if(a == b) {
    cout << "Yes" << endl;
  } else if((find(a.begin(), a.end(), x) != a.end()) &&
            (find(a.begin(), a.end(), y) != a.end())){
    cout << "Yes" << endl;
  } else if((find(b.begin(), b.end(), x) != b.end()) &&
            (find(b.begin(), b.end(), y) != b.end())){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
