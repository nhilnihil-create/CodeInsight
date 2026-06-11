#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> button(n);
  for (int i = 0; i < n; i++)
    cin >> button.at(i);
  
  int i;
  bool meetTwo = false;
  int num = button.at(0);
  for (i = 0; i < n; i++){
    if (num == 2){
      meetTwo = true;
      break;
    }
  	num = button.at(num - 1);
  }
  if (meetTwo == true)
    cout << i + 1 << endl;
  else
    cout << -1 << endl;
}