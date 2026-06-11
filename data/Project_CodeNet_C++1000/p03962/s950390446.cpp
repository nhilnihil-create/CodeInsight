#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
vector<int> vec(3);
cin >> vec.at(0) >> vec.at(1) >> vec.at(2);
set<int> se;
rep(i,3) se.insert(vec.at(i));

cout << se.size() << endl;

return 0;
}