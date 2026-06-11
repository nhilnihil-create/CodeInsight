#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
  int a,b,ans=0;
  cin >> a >> b;
  vector<int> ai(a);
  for(int i = 0;i<a;i++)cin >> ai.at(i);
  sort(ai.begin(),ai.end());
  reverse(ai.begin(),ai.end());
  for(int i = 0;i<b;i++) ans += ai.at(i);
  cout << ans;
}