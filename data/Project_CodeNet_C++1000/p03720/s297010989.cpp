#include <bits/stdc++.h>
using namespace std;

int main() {
  	int n,h,a,b;
  cin >> n >> h;
  vector<int> counter(n);
  for(int i = 0;i < h;i++){
    cin >> a >> b;
    counter.at(a-1)++;
    counter.at(b-1)++;
  }
  for (int k = 0;k < n;k++){
    cout << counter.at(k) << endl;
  }
  
  
}