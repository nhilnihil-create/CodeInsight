#include<iostream>
#include<algorithm>
using namespace std;


int main(){
  int k, t;
  cin >> k >> t;
  int a[100];
  int max_a = 0;
  for(int i=0; i<t; ++i){
    cin >> a[i];
    max_a = max(max_a, a[i]);
  }
  int ans;
  ans = 2 * max_a - k - 1;
  cout << max(ans, 0) << endl;
}
