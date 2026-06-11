#include<iostream>
#include<algorithm>
using namespace std;
int main() {
  int ans = 0;
  int ma = 0;
  int n;cin >> n;
  for(int i = 0;i<n;i++) {
    char c;cin >> c;
    if(c=='I') ans++;
    else ans--;
    ma=max(ma,ans);
  }
  cout << ma << endl;
}