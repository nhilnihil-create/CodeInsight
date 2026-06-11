#include<bits/stdc++.h>
using namespace std;

int main(void){
  int abc[3];
  for(int i = 0; i < 3; i++)
    cin >> abc[i];
  sort(begin(abc), end(abc));
  cout << abc[0] + abc[1] << "\n";
  return 0;
}
