#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()

int main() {
    int a,b;
    cin >> a >> b;
    vector<string> vector(a);
    rep(i,a){
      cin >> vector.at(i);
    }
    sort(vector.begin(), vector.end());
  rep(i,a){
      cout << vector.at(i);
    }
  cout << endl;
}