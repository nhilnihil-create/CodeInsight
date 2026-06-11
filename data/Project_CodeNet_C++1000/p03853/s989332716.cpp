#include <bits/stdc++.h>
using namespace std;

const int INF = 1001001001;

int main() {
int h,w;
cin >> h >> w;
vector<string> vec(h);
for (int i = 0;i < h;i++) {
    cin >> vec.at(i);
} 

for (int i = 0;i < h;i++) {
  for (int j = 0;j < 2;j++) {
    cout << vec.at(i) << endl;
  }
}



return 0;
}